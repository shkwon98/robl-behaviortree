#include "robl_behavior_tree/filesystem/find_file_node.h"

namespace robl_behavior_tree
{

BT::NodeStatus FindFileNode::tick()
{
    std::string path;
    std::string expression;

    if (!getInput("path", path))
    {
        throw BT::RuntimeError("missing required input [path]");
    }
    if (!getInput("expression", expression))
    {
        throw BT::RuntimeError("missing required input [expression]");
    }

    if (!std::filesystem::exists(path))
    {
        throw BT::RuntimeError("path does not exist: ", path);
    }

    // Find files that match the expression in the given path
    // path can be a directory or a file
    std::vector<std::string> files;
    if (std::filesystem::is_directory(path))
    {
        for (const auto &entry : std::filesystem::directory_iterator(path))
        {
            if (entry.is_regular_file())
            {
                auto filepath = entry.path().string();
                auto filename = entry.path().filename().string();

                if (std::regex_match(filename, std::regex(expression)))
                {
                    files.push_back(filepath);
                }
            }
        }
    }
    else if (std::filesystem::is_regular_file(path))
    {
        auto filename = std::filesystem::path(path).filename().string();
        if (std::regex_match(filename, std::regex(expression)))
        {
            files.push_back(path);
        }
    }

    if (files.empty())
    {
        return BT::NodeStatus::FAILURE;
    }

    setOutput("files", files);
    return BT::NodeStatus::SUCCESS;
}

} // namespace robl_behavior_tree