# Environment options

This project support of getting options from the environment variables.

## Supported options

  * `ZSWAP_ENABLED_VALUE` - enable (`Y`) or disable (`N`) the ZSwap kernel module.
  * `ZSWAP_SAME_FILLED_PAGES_ENABLED_VALUE` - enable (`Y`) or disable (`N`) memory pages deduplication.
  * `ZSWAP_MAX_POOL_PERCENT_VALUE` - the maximum percentage of memory that the compressed pool can occupy (integer from `1` to `100`).
  * `ZSWAP_COMPRESSOR_VALUE` - the algorithm used to compress memory pages.
  * `ZSWAP_ZPOOL_VALUE` - the kernel's zpool type.
  * `ZSWAP_ACCEPT_THRESHOLD_PERCENT_VALUE` - the threshold at which ZSwap would start accepting pages again after it became full (integer from `1` to `100`).

## Forwarding options

Export the environment variables using the `export` command:

```bash
export ZSWAP_ENABLED_VALUE=Y
export ZSWAP_SAME_FILLED_PAGES_ENABLED_VALUE=Y
export ZSWAP_MAX_POOL_PERCENT_VALUE=60
export ZSWAP_COMPRESSOR_VALUE=zstd
export ZSWAP_ZPOOL_VALUE=z3fold
export ZSWAP_ACCEPT_THRESHOLD_PERCENT_VALUE=40
```

Start the application with the `--env` command-line argument:

```
sudo zswap-cli --env
```
