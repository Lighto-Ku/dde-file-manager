cmake_minimum_required(VERSION 3.10)

project(dfmplugin-titlebar)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

FILE(GLOB_RECURSE TITLEBAR_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.json"
    )

# Qt6
if (DFM_BUILD_WITH_QT6)
    include(dfmplugin-titlebar-qt6.cmake)
else()
    include(dfmplugin-titlebar-qt5.cmake)
endif()
