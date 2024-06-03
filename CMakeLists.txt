cmake_minimum_required(VERSION 3.14)

project(robl_behavior_tree
    LANGUAGES CXX)

### Project Settings ###
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

### Dependencies ###
include(cmake/external/behaviortree_cpp.cmake)
include(cmake/external/libarchive.cmake)

### robl_behavior_tree::filesystem ###
file(GLOB_RECURSE filesystem_sources CONFIGURE_DEPENDS src/filesystem/*.cpp)
add_library(robl_behavior_tree-filesystem SHARED)
target_sources(robl_behavior_tree-filesystem
    PRIVATE ${filesystem_sources})
target_include_directories(robl_behavior_tree-filesystem
    PUBLIC  include)
target_link_libraries(robl_behavior_tree-filesystem
    PUBLIC  BT::behaviortree_cpp)
set_target_properties(robl_behavior_tree-filesystem
    PROPERTIES
        INSTALL_RPATH "$ORIGIN"
        COMPILE_DEFINITIONS BT_PLUGIN_EXPORT)
add_library(robl_behavior_tree::filesystem ALIAS robl_behavior_tree-filesystem)

### robl_behavior_tree::archive ###
file(GLOB_RECURSE archive_sources CONFIGURE_DEPENDS src/archive/*.cpp)
add_library(robl_behavior_tree-archive SHARED)
target_sources(robl_behavior_tree-archive
    PRIVATE ${archive_sources})
target_include_directories(robl_behavior_tree-archive
    PUBLIC  include)
target_link_libraries(robl_behavior_tree-archive
    PRIVATE LibArchive::LibArchive
    PUBLIC  BT::behaviortree_cpp)
set_target_properties(robl_behavior_tree-archive
    PROPERTIES
        INSTALL_RPATH "$ORIGIN"
        COMPILE_DEFINITIONS BT_PLUGIN_EXPORT)
add_library(robl_behavior_tree::archive ALIAS robl_behavior_tree-archive)

### robl_behavior_tree::robl_behavior_tree ###
add_library(robl_behavior_tree INTERFACE)
target_link_libraries(robl_behavior_tree
    INTERFACE robl_behavior_tree::filesystem
              robl_behavior_tree::archive)
add_library(robl_behavior_tree::robl_behavior_tree ALIAS robl_behavior_tree)


### install ###
install(TARGETS robl_behavior_tree-filesystem
                robl_behavior_tree-archive
                robl_behavior_tree
        EXPORT robl_behavior_tree-targets
        LIBRARY DESTINATION lib
        INCLUDES DESTINATION include)

