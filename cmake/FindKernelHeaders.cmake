find_path(KERNELHEADERS_PATH
    NAMES "linux/kernel.h"
)

if (NOT KERNELHEADERS_PATH)
    message(FATAL_ERROR "Linux kernel headers were not found.")
endif()
