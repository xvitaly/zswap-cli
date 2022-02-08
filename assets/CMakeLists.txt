#
# SPDX-FileCopyrightText: 2020-2022 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

if (BUILD_DOC)
    doxygen_add_docs(${DOCS_NAME} src docs ALL WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} COMMENT "Building documentation with Doxygen.")
    install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/html/" DESTINATION ${CMAKE_INSTALL_DOCDIR})
endif()

if (BUILD_MANPAGE)
    configure_file("manpage/${CMAKE_PROJECT_NAME}.md.in" "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.md" @ONLY)
    add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1" COMMAND "${Pandoc_EXECUTABLE}" ARGS "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.md" -s -t man -o "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1" COMMENT "Building manpage using Pandoc." VERBATIM)
    add_custom_target(${MAN_NAME} ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1")
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1" DESTINATION "${CMAKE_INSTALL_MANDIR}/man1")
endif()

if (SYSTEMD_INTEGRATION)
    configure_file("systemd/${CMAKE_PROJECT_NAME}.service.in" "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.service" @ONLY)
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.service" DESTINATION "lib/systemd/system")
endif()

install(FILES "config/${CMAKE_PROJECT_NAME}.conf" DESTINATION "${CMAKE_INSTALL_FULL_SYSCONFDIR}/${CMAKE_PROJECT_NAME}" RENAME "${APP_NAME}.conf")
