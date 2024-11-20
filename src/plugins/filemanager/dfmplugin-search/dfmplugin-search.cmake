if (${CMAKE_SYSTEM_PROCESSOR} MATCHES "aarch64")
    ADD_DEFINITIONS(-DARM_PROCESSOR)
endif()

find_package(Dtk${DTK_VERSION_MAJOR} COMPONENTS Widget REQUIRED)
find_package(PkgConfig REQUIRED)

#full-text search dependences
pkg_check_modules(Lucene REQUIRED IMPORTED_TARGET liblucene++ liblucene++-contrib)
pkg_check_modules(Docparser REQUIRED IMPORTED_TARGET docparser)
pkg_check_modules(GLIB REQUIRED glib-2.0)
pkg_check_modules(PCRE REQUIRED libpcre)

add_library(${PROJECT_NAME}
    SHARED
    ${SRC}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${DFM_BUILD_PLUGIN_FILEMANAGER_DIR})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${DtkWidget_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty
        ${GLIB_INCLUDE_DIRS}
        ${PCRE_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    DFM${DTK_VERSION_MAJOR}::base
    DFM${DTK_VERSION_MAJOR}::framework
    ${DtkWidget_LIBRARIES}
    ${GLIB_LIBRARIES}
    ${PCRE_LIBRARIES}
    PkgConfig::Lucene
    PkgConfig::Docparser
)

#install library file
install(TARGETS
    ${PROJECT_NAME}
    LIBRARY
    DESTINATION
    ${DFM_PLUGIN_FILEMANAGER_EDGE_DIR}
)
