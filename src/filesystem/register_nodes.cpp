#include "robl_behavior_tree/filesystem/copy_file_node.h"
#include "robl_behavior_tree/filesystem/find_file_node.h"
#include "robl_behavior_tree/filesystem/get_file_type_node.h"

#include <behaviortree_cpp/bt_factory.h>

BT_REGISTER_NODES(factory)
{
    factory.registerNodeType<robl_behavior_tree::CopyFile>("CopyFile");
    factory.registerNodeType<robl_behavior_tree::FindFile>("FindFile");
    factory.registerNodeType<robl_behavior_tree::GetFileType>("GetFileType");
}
