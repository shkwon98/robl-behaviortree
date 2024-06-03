#pragma once

#include <filesystem>

#include <behaviortree_cpp/action_node.h>

namespace robl_behaviortree
{

// This is a synchronous operation
class CopyFileNode : public BT::SyncActionNode
{
public:
    CopyFileNode(const std::string &name, const BT::NodeConfig &config)
        : BT::SyncActionNode(name, config)
    {
    }

    static BT::PortsList providedPorts()
    {
        return { BT::InputPort<std::string>("src"), BT::InputPort<std::string>("dest"),
                 BT::OutputPort<std::string>("output") };
    }

    BT::NodeStatus tick() override;

private:
};

} // namespace robl_behaviortree