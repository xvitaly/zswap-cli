# Configuration files

zswap-cli support of getting options from the configuration files.

## Supported options

  * `enabled` - enable (`Y`) or disable (`N`) ZSwap kernel module.
  * `same_filled_pages_enabled` - enable (`Y`) or disable (`N`) memory pages deduplication.
  * `max_pool_percent` - the maximum percentage of memory that the compressed pool can occupy (integer from `1` to `100`).
  * `compressor` - the default compression algorithm.
  * `zpool` - the kernel's zpool type.
  * `accept_threhsold_percent` - the threshold at which ZSwap would start accepting pages again after it became full (integer from `1` to `100`).

## Forwarding options

Start application with `--config` command-line argument:

```
sudo zswap-cli --config /path/to/zswap-cli.conf
```
