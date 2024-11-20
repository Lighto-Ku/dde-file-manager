add_library(${PROJECT_NAME}
    SHARED
    ${COMPUTER_FILES}
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(Secret REQUIRED libsecret-1)

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core)
set_target_properties(${PROJECT_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${DFM_BUILD_PLUGIN_FILEMANAGER_DIR})

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${Secret_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    DFM${DTK_VERSION_MAJOR}::base
    DFM${DTK_VERSION_MAJOR}::framework
    ${Secret_LIBRARIES}
)

#install library file
install(TARGETS
    ${PROJECT_NAME}
    LIBRARY
    DESTINATION
    ${DFM_PLUGIN_FILEMANAGER_CORE_DIR}
)

set(AppEntryInstallDir "${CMAKE_INSTALL_PREFIX}/share/dde-file-manager/extensions/appEntry")
install(FILES .readme DESTINATION ${AppEntryInstallDir})