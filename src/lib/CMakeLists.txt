set(SOURCES
    cwrappers/cwrappers.cpp
    ksysinfo/ksysinfo.cpp
    zswapworker/zswapworker.cpp
    zswapobject/zswapobject.cpp
    zswapdebug/zswapdebug.cpp
)

set(HEADERS
    cwrappers/cwrappers.hpp
    ksysinfo/ksysinfo.hpp
    zswapworker/zswapworker.hpp
    zswapobject/zswapobject.hpp
    zswapdebug/zswapdebug.hpp
)

set(INTERNAL_LIBS
    ${SOURCES}
    ${HEADERS}
)

set(EXTERNAL_LIBS
    fmt::fmt
)

add_library(${LIB_NAME} STATIC
    ${INTERNAL_LIBS}
)

target_link_libraries(${LIB_NAME} PRIVATE ${EXTERNAL_LIBS})

if (BUILD_DOC)
    find_package(Doxygen)
    if (DOXYGEN_FOUND)
        configure_file("${PROJECT_SOURCE_DIR}/packaging/assets/Doxyfile.in" "${PROJECT_SOURCE_DIR}/Doxyfile" @ONLY)
        add_custom_command(OUTPUT "${PROJECT_SOURCE_DIR}/Doxyfile" COMMAND ${DOXYGEN_EXECUTABLE} ARGS ${PROJECT_SOURCE_DIR}/Doxyfile WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} COMMENT "Generating documentation with Doxygen." VERBATIM)
        add_custom_target(zswap-doxygen ALL DEPENDS "${PROJECT_SOURCE_DIR}/Doxyfile")
    endif()
endif()
