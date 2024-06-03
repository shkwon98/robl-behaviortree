#include "robl_behaviortree/archive/extract_archive_node.h"

#include <behaviortree_cpp/bt_factory.h>

BT_REGISTER_NODES(factory)
{
    factory.registerNodeType<robl_behaviortree::ExtractArchiveNode>("ExtractArchive");
}
