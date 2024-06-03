#pragma once

#include <filesystem>
#include <regex>

#include <behaviortree_cpp/action_node.h>

namespace robl_behavior_tree
{

// This is a synchronous operation
class FindFileNode : public BT::SyncActionNode
{
public:
    FindFileNode(const std::string &name, const BT::NodeConfig &config)
        : BT::SyncActionNode(name, config)
    {
    }

    static BT::PortsList providedPorts()
    {
        return { BT::InputPort<std::string>("path"), BT::InputPort<std::string>("expression"),
                 BT::OutputPort<std::vector<std::string>>("files") };
    }

    BT::NodeStatus tick() override;

private:
};

} // namespace robl_behavior_tree