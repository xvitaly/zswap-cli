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

configure_file("${PROJECT_SOURCE_DIR}/assets/${CMAKE_PROJECT_NAME}.service.in" "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.service" @ONLY)
install(TARGETS ${APP_NAME} DESTINATION "${CMAKE_INSTALL_SBINDIR}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.service" DESTINATION "lib/systemd/system")
install(FILES "${PROJECT_SOURCE_DIR}/assets/${CMAKE_PROJECT_NAME}.conf" DESTINATION "${CMAKE_INSTALL_FULL_SYSCONFDIR}")
