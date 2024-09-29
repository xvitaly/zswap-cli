# Configuration files

This project support of getting options from the configuration files.

## Supported options

  * `enabled` - enable (`Y`) or disable (`N`) the ZSwap kernel module.
  * `same_filled_pages_enabled` (requires kernel `4.16.0` to `6.10.0`) - enable (`Y`) or disable (`N`) memory pages deduplication.
  * `max_pool_percent` - the maximum percentage of memory that the compressed pool can occupy (integer from `1` to `100`).
  * `compressor` - the algorithm used to compress memory pages.
  * `zpool` - the kernel's zpool type.
  * `accept_threshold_percent` (requires kernel `5.6.0` or higher) - the threshold at which ZSwap would start accepting pages again after it became full (integer from `1` to `100`).
  * `non_same_filled_pages_enabled` (requires kernel `5.18.0` to `6.10.0`) - enable (`Y`) or disable (`N`) accepting non same filled memory pages.
  * `exclusive_loads` (requires kernel `6.5.0` to `6.9.0`) - enable (`Y`) or disable (`N`) entries invalidation when memory pages are loaded from compressed pool.
  * `shrinker_enabled` (requires kernel `6.8.0` or higher) - enable (`Y`) or disable (`N`) pool shrinking based on memory pressure.

## Forwarding options

Start the application with the `--config` command-line argument:

```
sudo zswap-cli --config /path/to/zswap-cli.conf
```
