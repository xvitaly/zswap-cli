# Configuration files

This project support of getting options from the configuration files.

## Supported options

  * `enabled` - enable (`Y`) or disable (`N`) the ZSwap kernel module.
  * `same_filled_pages_enabled` - enable (`Y`) or disable (`N`) memory pages deduplication.
  * `max_pool_percent` - the maximum percentage of memory that the compressed pool can occupy (integer from `1` to `100`).
  * `compressor` - the algorithm used to compress memory pages.
  * `zpool` - the kernel's zpool type.
  * `accept_threshold_percent` - the threshold at which ZSwap would start accepting pages again after it became full (integer from `1` to `100`).

## Forwarding options

Start the application with the `--config` command-line argument:

```
sudo zswap-cli --config /path/to/zswap-cli.conf
```
