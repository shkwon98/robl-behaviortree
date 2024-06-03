#pragma once

#include <filesystem>
#include <regex>

#include <behaviortree_cpp/action_node.h>

namespace robl_behavior_tree
{

// This is a synchronous operation
class GetFileTypeNode : public BT::SyncActionNode
{
public:
    GetFileTypeNode(const std::string &name, const BT::NodeConfig &config)
        : BT::SyncActionNode(name, config)
    {
    }

    static BT::PortsList providedPorts()
    {
        return { BT::InputPort<std::string>("file"), BT::OutputPort<std::string>("type") };
    }

    BT::NodeStatus tick() override;

private:
};

} // namespace robl_behavior_tree