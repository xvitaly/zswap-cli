set(SOURCES
    cwrappers/cwrappers.cpp
    zswapworker/zswapworker.cpp
    zswapobject/zswapobject.cpp
    zswaphelper/zswaphelper.cpp
    zswapdebug/zswapdebug.cpp
)

set(HEADERS
    cwrappers/cwrappers.hpp
    zswapworker/zswapworker.hpp
    zswapobject/zswapobject.hpp
    zswaphelper/zswaphelper.hpp
    zswapdebug/zswapdebug.hpp
)

set(INTERNAL_LIBS
    ${SOURCES}
    ${HEADERS}
)

add_library(zswap-lib STATIC
    ${INTERNAL_LIBS}
)
