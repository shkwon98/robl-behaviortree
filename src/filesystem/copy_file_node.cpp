#include "robl_behavior_tree/filesystem/copy_file_node.h"

namespace robl_behavior_tree
{

BT::NodeStatus CopyFileNode::tick()
{
    std::string src;
    std::string dest;

    if (!getInput("src", src))
    {
        throw BT::RuntimeError("missing required input [src]");
    }
    if (!getInput("dest", dest))
    {
        throw BT::RuntimeError("missing required input [dest]");
    }

    std::filesystem::copy(src, dest, std::filesystem::copy_options::update_existing);

    auto output = (std::filesystem::path(dest) / std::filesystem::path(src).filename()).string();

    std::cout << "Copied " << src << " to " << output << std::endl;

    setOutput("output", output);
    return BT::NodeStatus::SUCCESS;
}

} // namespace robl_behavior_tree