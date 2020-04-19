set(SOURCES
    cwrappers/cwrappers.cpp
    zswapworker/zswapworker.cpp
    zswapobject/zswapobject.cpp
    zswapdebug/zswapdebug.cpp
)

set(HEADERS
    cwrappers/cwrappers.hpp
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

add_library(zswap-lib STATIC
    ${INTERNAL_LIBS}
)

target_link_libraries(zswap-lib PRIVATE ${EXTERNAL_LIBS})
