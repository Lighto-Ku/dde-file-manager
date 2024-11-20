cmake_minimum_required(VERSION 3.10)

project(dfmplugin-sidebar)

add_definitions(-DSIDEBAR_TREEVIEW)
set(SIDEBAR_TREEVIEW ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if (SIDEBAR_TREEVIEW)
    add_definitions(-DTREEVIEW)
    message("Sidebar is implemented with tree view")
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/treeviews)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/treemodels)
    FILE(GLOB SIDEBAR_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/utils/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/utils/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/events/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/events/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/treemodels/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/treemodels/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/treeviews/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/treeviews/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/treeviews/private/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.json"
    )
else()
    message("Sidebar is implemented with list view")
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/views)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/models)
    FILE(GLOB SIDEBAR_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/utils/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/utils/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/events/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/events/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/models/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/models/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/views/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/views/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/views/private/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.json"
    )
endif()

# Qt6
if (DFM_BUILD_WITH_QT6)
    include(dfmplugin-sidebar-qt6.cmake)
else()
    include(dfmplugin-sidebar-qt5.cmake)
endif()

# install dconfig files.
INSTALL_DCONFIG("org.deepin.dde.file-manager.sidebar.json")

