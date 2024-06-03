#include "robl_behaviortree/logger/say_something_node.h"

#include <behaviortree_cpp/bt_factory.h>

BT_REGISTER_NODES(factory)
{
    factory.registerNodeType<robl_behaviortree::SaySomethingNode>("SaySomething");
}
