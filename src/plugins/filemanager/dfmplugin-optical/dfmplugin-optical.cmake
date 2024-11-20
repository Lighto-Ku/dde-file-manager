find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Svg REQUIRED)
set(SVGLIB Qt${QT_VERSION_MAJOR}::Svg)

if (QT_VERSION_MAJOR EQUAL 6)
    find_package(Qt6 REQUIRED COMPONENTS SvgWidgets)
endif()

add_library(${PROJECT_NAME}
    SHARED
    ${OPTICAL_FILES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${DFM_BUILD_PLUGIN_FILEMANAGER_DIR})


if (QT_VERSION_MAJOR EQUAL 6)
    target_link_libraries(${PROJECT_NAME}
        ${SVGLIB}
        Qt6::SvgWidgets
        DFM${DTK_VERSION_MAJOR}::base
        DFM${DTK_VERSION_MAJOR}::framework
    )
else()
    target_link_libraries(${PROJECT_NAME}
        ${SVGLIB}
        DFM${DTK_VERSION_MAJOR}::base
        DFM${DTK_VERSION_MAJOR}::framework
    )
endif()

#install library file
install(TARGETS
    ${PROJECT_NAME}
    LIBRARY
    DESTINATION
    ${DFM_PLUGIN_FILEMANAGER_EDGE_DIR}
)