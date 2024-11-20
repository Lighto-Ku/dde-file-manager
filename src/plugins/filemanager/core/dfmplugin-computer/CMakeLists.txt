cmake_minimum_required(VERSION 3.10)

project(dfmplugin-computer)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

FILE(GLOB_RECURSE COMPUTER_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.json"
    )

# Qt6
if (DFM_BUILD_WITH_QT6)
    include(dfmplugin-computer-qt6.cmake)
else()
    include(dfmplugin-computer-qt5.cmake)
endif()

# install dconfig files.
INSTALL_DCONFIG("org.deepin.dde.file-manager.computer.json")
INSTALL_DCONFIG("org.deepin.dde.file-manager.mount.json")
