# make dbus service file and install
function (INSTALL_DBUS_SERVICE ARG)
    if (${ARGC} EQUAL 1)
        file(GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${ARGV0}.service CONTENT "[D-BUS Service]\nName=${ARGV0}\nExec=/usr/bin/deepin-service-manager -n ${ARGV0}\nSystemdService=deepin-service-plugin@${ARGV0}.service")
        install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${ARGV0}.service DESTINATION ${CMAKE_INSTALL_FULL_DATADIR}/dbus-1/services)
    endif()
    if (${ARGC} EQUAL 2)
        file(GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${ARGV0}.service CONTENT "[D-BUS Service]\nName=${ARGV0}\nExec=/usr/bin/deepin-service-manager -n ${ARGV0}\nUser=root\nSystemdService=deepin-service-plugin@${ARGV0}.service")
        install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${ARGV0}.service DESTINATION ${CMAKE_INSTALL_FULL_DATADIR}/dbus-1/system-services)
    endif()
endfunction ()
