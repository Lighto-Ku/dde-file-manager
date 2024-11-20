find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Xml DBus REQUIRED)

if(${QT_VERSION_MAJOR} EQUAL "6")
    qt6_add_dbus_interface(RECENT_FILES
        ${DFM_DBUS_XML_DIR}/org.deepin.Filemanager.Daemon.RecentManager.xml
        recentmanager_interface)
else()
   # generate dbus interface
    qt5_add_dbus_interface(RECENT_FILES
        ${DFM_DBUS_XML_DIR}/org.deepin.Filemanager.Daemon.RecentManager.xml
        recentmanager_interface)
endif()

add_library(${PROJECT_NAME}
    SHARED
    ${RECENT_FILES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${DFM_BUILD_PLUGIN_FILEMANAGER_DIR})

target_link_libraries(${PROJECT_NAME}
    DFM${DTK_VERSION_MAJOR}::base
    DFM${DTK_VERSION_MAJOR}::framework
    Qt${QT_VERSION_MAJOR}::Xml
    Qt${QT_VERSION_MAJOR}::DBus
)

#install library file
install(TARGETS
    ${PROJECT_NAME}
    LIBRARY
    DESTINATION
    ${DFM_PLUGIN_FILEMANAGER_CORE_DIR}
)

