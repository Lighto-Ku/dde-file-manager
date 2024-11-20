add_library(${PROJECT_NAME}
    SHARED
    ${SIDEBAR_FILES}
)

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core)
set_target_properties(${PROJECT_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${DFM_BUILD_PLUGIN_FILEMANAGER_DIR})

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






