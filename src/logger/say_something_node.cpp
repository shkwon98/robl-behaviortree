#include "robl_behaviortree/logger/say_something_node.h"

namespace robl_behaviortree
{

BT::NodeStatus SaySomethingNode::tick()
{
    auto msg = getInput<std::string>("message");
    if (!msg)
    {
        throw BT::RuntimeError("missing required input [message]: ", msg.error());
    }

    std::cout << "Tree says: " << msg.value() << std::endl;
    return BT::NodeStatus::SUCCESS;
}

}; // namespace robl_behaviortree
