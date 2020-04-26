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
    zswap-lib
    fmt::fmt
)

add_executable(zswap-cli ${INTERNAL_LIBS})
target_link_libraries(zswap-cli PRIVATE ${EXTERNAL_LIBS})

configure_file("${CMAKE_SOURCE_DIR}/packaging/assets/zswap-cli.service.in" "${CMAKE_CURRENT_BINARY_DIR}/zswap-cli.service" @ONLY)
install(TARGETS zswap-cli DESTINATION "${CMAKE_INSTALL_SBINDIR}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/zswap-cli.service" DESTINATION "lib/systemd/system")
install(FILES "${CMAKE_SOURCE_DIR}/packaging/assets/zswap-cli.conf" DESTINATION "${CMAKE_INSTALL_FULL_SYSCONFDIR}")

if (Pandoc_FOUND)
    add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/zswap-cli.1" COMMAND "${Pandoc_EXECUTABLE}" ARGS "${CMAKE_SOURCE_DIR}/packaging/assets/manpage.md" -s -t man -o "${CMAKE_CURRENT_BINARY_DIR}/zswap-cli.1" COMMENT "Building manpage using Pandoc." VERBATIM)
    add_custom_target(zswap-man ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/zswap-cli.1")
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/zswap-cli.1" DESTINATION "${CMAKE_INSTALL_MANDIR}/man1")
endif()
