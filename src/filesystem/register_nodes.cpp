#include "robl_behaviortree/filesystem/copy_file_node.h"
#include "robl_behaviortree/filesystem/find_file_node.h"
#include "robl_behaviortree/filesystem/get_file_type_node.h"

#include <behaviortree_cpp/bt_factory.h>

BT_REGISTER_NODES(factory)
{
    factory.registerNodeType<robl_behaviortree::CopyFileNode>("CopyFile");
    factory.registerNodeType<robl_behaviortree::FindFileNode>("FindFile");
    factory.registerNodeType<robl_behaviortree::GetFileTypeNode>("GetFileType");
}
