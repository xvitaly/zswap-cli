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
    fmt::fmt
    zswap-lib
)

add_executable(zswap-cli ${INTERNAL_LIBS})
target_link_libraries(zswap-cli PRIVATE ${EXTERNAL_LIBS})

configure_file("${CMAKE_SOURCE_DIR}/packaging/assets/zswap-cli.service.in" "${CMAKE_CURRENT_BINARY_DIR}/zswap-cli.service" @ONLY)

install(TARGETS zswap-cli DESTINATION "${CMAKE_INSTALL_SBINDIR}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/zswap-cli.service" DESTINATION "lib/systemd/system")
install(FILES "${CMAKE_SOURCE_DIR}/packaging/assets/zswap-cli.default" DESTINATION "${CMAKE_INSTALL_FULL_SYSCONFDIR}/default" RENAME "zswap-cli")
