set(SOURCES
    application/application.cpp
    main.cpp
)

set(HEADERS
    application/application.hpp
)

set(INTERNAL_LIBS
    ${SOURCES}
    ${HEADERS}
)

set(EXTERNAL_LIBS
    ${LIB_NAME}
    fmt::fmt
    Boost::program_options
)

add_executable(${APP_NAME} ${INTERNAL_LIBS})
target_link_libraries(${APP_NAME} PRIVATE ${EXTERNAL_LIBS})

configure_file("${PROJECT_SOURCE_DIR}/packaging/assets/${CMAKE_PROJECT_NAME}.service.in" "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.service" @ONLY)
install(TARGETS ${APP_NAME} DESTINATION "${CMAKE_INSTALL_SBINDIR}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.service" DESTINATION "lib/systemd/system")
install(FILES "${PROJECT_SOURCE_DIR}/packaging/assets/${CMAKE_PROJECT_NAME}.conf" DESTINATION "${CMAKE_INSTALL_FULL_SYSCONFDIR}")

if (Pandoc_FOUND)
    add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1" COMMAND "${Pandoc_EXECUTABLE}" ARGS "${PROJECT_SOURCE_DIR}/packaging/assets/manpage.md" -s -t man -o "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1" COMMENT "Building manpage using Pandoc." VERBATIM)
    add_custom_target(${MAN_NAME} ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1")
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1" DESTINATION "${CMAKE_INSTALL_MANDIR}/man1")
endif()
