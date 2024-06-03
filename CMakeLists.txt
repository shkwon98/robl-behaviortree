cmake_minimum_required(VERSION 3.14)

project(robl-behaviortree
    LANGUAGES CXX)

### Project Settings ###
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

### Dependencies ###
include(cmake/external/behaviortree_cpp.cmake)
include(cmake/external/libarchive.cmake)

### robl::behaviortree_filesystem ###
file(GLOB_RECURSE filesystem_sources CONFIGURE_DEPENDS src/filesystem/*.cpp)
add_library(robl-behaviortree-filesystem SHARED)
target_sources(robl-behaviortree-filesystem
    PRIVATE ${filesystem_sources})
target_include_directories(robl-behaviortree-filesystem
    PUBLIC  include)
target_link_libraries(robl-behaviortree-filesystem
    PUBLIC  BT::behaviortree_cpp)
set_target_properties(robl-behaviortree-filesystem
    PROPERTIES
        INSTALL_RPATH "$ORIGIN"
        COMPILE_DEFINITIONS BT_PLUGIN_EXPORT)
add_library(robl::behaviortree_filesystem ALIAS robl-behaviortree-filesystem)

### robl::behaviortree_archive ###
file(GLOB_RECURSE archive_sources CONFIGURE_DEPENDS src/archive/*.cpp)
add_library(robl-behaviortree-archive SHARED)
target_sources(robl-behaviortree-archive
    PRIVATE ${archive_sources})
target_include_directories(robl-behaviortree-archive
    PUBLIC  include)
target_link_libraries(robl-behaviortree-archive
    PRIVATE LibArchive::LibArchive
    PUBLIC  BT::behaviortree_cpp)
set_target_properties(robl-behaviortree-archive
    PROPERTIES
        INSTALL_RPATH "$ORIGIN"
        COMPILE_DEFINITIONS BT_PLUGIN_EXPORT)
add_library(robl::behaviortree_archive ALIAS robl-behaviortree-archive)

### robl::behaviortree_logger ###
file(GLOB_RECURSE logger_sources CONFIGURE_DEPENDS src/logger/*.cpp)
add_library(robl-behaviortree-logger SHARED)
target_sources(robl-behaviortree-logger
    PRIVATE ${logger_sources})
target_include_directories(robl-behaviortree-logger
    PUBLIC  include)
target_link_libraries(robl-behaviortree-logger
    PUBLIC  BT::behaviortree_cpp)
set_target_properties(robl-behaviortree-logger
    PROPERTIES
        INSTALL_RPATH "$ORIGIN"
        COMPILE_DEFINITIONS BT_PLUGIN_EXPORT)
add_library(robl::behaviortree_logger ALIAS robl-behaviortree-logger)

### robl::behaviortree ###
add_library(robl-behaviortree INTERFACE)
target_link_libraries(robl-behaviortree
    INTERFACE robl::behaviortree_filesystem
              robl::behaviortree_archive
                robl::behaviortree_logger)
add_library(robl::behaviortree ALIAS robl-behaviortree)


### install ###
install(TARGETS robl-behaviortree-filesystem
                robl-behaviortree-archive
                robl-behaviortree-logger
                robl-behaviortree
        EXPORT robl-behaviortree-targets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY include/robl-behaviortree
        DESTINATION include
        FILES_MATCHING PATTERN "*.h*")

