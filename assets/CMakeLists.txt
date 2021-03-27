if (BUILD_DOC)
    doxygen_add_docs(${DOCS_NAME} src docs ALL WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} COMMENT "Building documentation with Doxygen.")
endif()

if (BUILD_MANPAGE)
    add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1" COMMAND "${Pandoc_EXECUTABLE}" ARGS "${PROJECT_SOURCE_DIR}/assets/manpage.md" -s -t man -o "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1" COMMENT "Building manpage using Pandoc." VERBATIM)
    add_custom_target(${MAN_NAME} ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1")
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1" DESTINATION "${CMAKE_INSTALL_MANDIR}/man1")
endif()
