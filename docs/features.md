# Features

Supported kernel module options:

| Name | Value | Status | Kernel version |
| ------- | ------- | ------- | ------- |
| enabled | **Y** (enable) or **N** (disable) | Active | Any |
| same_filled_pages_enabled | **Y** (enable) or **N** (disable) | Deprecated | 4.16.0 to 6.10.0 |
| max_pool_percent | integer from **1** to **100** | Active | Any |
| compressor | from supported by kernel | Active | Any |
| zpool | from supported by kernel | Active | Any |
| accept_threshold_percent | integer from **1** to **100** | Active | 5.6.0 or higher |
| non_same_filled_pages_enabled | **Y** (enable) or **N** (disable) | Deprecated | 5.18.0 to 6.10.0 |
| exclusive_loads | **Y** (enable) or **N** (disable) | Deprecated | 6.5.0 to 6.9.0 |
| shrinker_enabled | **Y** (enable) or **N** (disable) | Active | 6.8.0 or higher |

Deprecated functionality will be removed in future project versions.
