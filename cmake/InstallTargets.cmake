configure_file("${CMAKE_SOURCE_DIR}/packaging/assets/zswap-cli.service.in" "${CMAKE_CURRENT_BINARY_DIR}/zswap-cli.service" @ONLY)

install(TARGETS zswap-cli DESTINATION "${CMAKE_INSTALL_SBINDIR}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/zswap-cli.service" DESTINATION "lib/systemd/system")
install(FILES "${CMAKE_SOURCE_DIR}/packaging/assets/zswap-cli.default" DESTINATION "${CMAKE_INSTALL_FULL_SYSCONFDIR}/default" RENAME "zswap-cli")
