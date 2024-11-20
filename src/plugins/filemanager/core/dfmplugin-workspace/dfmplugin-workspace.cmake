add_library(${PROJECT_NAME}
    SHARED
    ${WORKSPACE_FILES}
)

find_package(Dtk${DTK_VERSION_MAJOR} COMPONENTS Widget REQUIRED)
set_target_properties(${PROJECT_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${DFM_BUILD_PLUGIN_FILEMANAGER_DIR})

if (QT_VERSION_MAJOR EQUAL "6")
    target_include_directories(${PROJECT_NAME} PRIVATE
        ${Qt6Widgets_PRIVATE_INCLUDE_DIRS}
    )
else()
    target_include_directories(${PROJECT_NAME} PRIVATE
        ${Qt5Widgets_PRIVATE_INCLUDE_DIRS}
    )
endif()

target_link_libraries(${PROJECT_NAME}
    DFM${DTK_VERSION_MAJOR}::base
    DFM${DTK_VERSION_MAJOR}::framework
)

#install library file
install(TARGETS
    ${PROJECT_NAME}
    LIBRARY
    DESTINATION
    ${DFM_PLUGIN_FILEMANAGER_CORE_DIR}
)
