set(SOURCES
    cwrappers/cwrappers.cpp
    zswapworker/zswapworker.cpp
    zswapobject/zswapobject.cpp
)

set(HEADERS
    cwrappers/cwrappers.hpp
    zswapworker/zswapworker.hpp
    zswapobject/zswapobject.hpp
)

set(INTERNAL_LIBS
    ${SOURCES}
    ${HEADERS}
)

add_library(zswap-lib STATIC
    ${INTERNAL_LIBS}
)
