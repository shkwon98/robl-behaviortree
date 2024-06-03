#pragma once

#include <behaviortree_cpp/action_node.h>

namespace robl_behaviortree
{

class SaySomethingNode : public BT::SyncActionNode
{
public:
    SaySomethingNode(const std::string &name, const BT::NodeConfig &config)
        : BT::SyncActionNode(name, config)
    {
    }

    static BT::PortsList providedPorts()
    {
        return { BT::InputPort<std::string>("message") };
    }

    BT::NodeStatus tick() override;

private:
};

} // namespace robl_behaviortree