#pragma once

#include <atomic>
#include <filesystem>
#include <future>

#include <behaviortree_cpp/action_node.h>

namespace robl_behaviortree
{

// This is an asynchronous operation
class ExtractArchiveNode : public BT::StatefulActionNode
{
public:
    ExtractArchiveNode(const std::string &name, const BT::NodeConfig &config)
        : BT::StatefulActionNode(name, config)
    {
    }

    static BT::PortsList providedPorts()
    {
        return { BT::InputPort<std::string>("file"), BT::OutputPort<std::string>("out_dir") };
    }

    BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
    void onHalted() override;

private:
    bool ExtractGzip(const std::string &file);

    std::string file_;
    std::atomic<float> progress_;
    std::future<bool> future_;
};

} // namespace robl_behaviortree