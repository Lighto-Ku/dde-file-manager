cmake_minimum_required(VERSION 3.10)

project(dfmplugin-trash)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

FILE(GLOB_RECURSE TRASH_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.json"
)

# Qt6
if (DFM_BUILD_WITH_QT6)
    include(dfmplugin-trash-qt6.cmake)
else()
    include(dfmplugin-trash-qt5.cmake)
endif()
