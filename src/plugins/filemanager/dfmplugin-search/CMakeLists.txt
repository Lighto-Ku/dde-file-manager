cmake_minimum_required(VERSION 3.10)

project(dfmplugin-search)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

FILE(GLOB_RECURSE
    SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.json"
)

# Qt6
if (DFM_BUILD_WITH_QT6)
    include(dfmplugin-search-qt6.cmake)
else()
    include(dfmplugin-search.cmake)
endif()

# install dconfig files.
INSTALL_DCONFIG("org.deepin.dde.file-manager.search.json")
