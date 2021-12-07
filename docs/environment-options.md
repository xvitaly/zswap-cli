# Environment options

zswap-cli support of getting options from environment variables.

## Supported options

  * `ZSWAP_ENABLED_VALUE` - enable (`Y`) or disable (`N`) ZSwap kernel module.
  * `ZSWAP_SAME_FILLED_PAGES_ENABLED_VALUE` - enable (`Y`) or disable (`N`) memory pages deduplication.
  * `ZSWAP_MAX_POOL_PERCENT_VALUE` - the maximum percentage of memory that the compressed pool can occupy (integer from `1` to `100`).
  * `ZSWAP_COMPRESSOR_VALUE` - the default compression algorithm.
  * `ZSWAP_ZPOOL_VALUE` - the kernel's zpool type.
  * `ZSWAP_ACCEPT_THREHSOLD_PERCENT_VALUE` - the threshold at which ZSwap would start accepting pages again after it became full (integer from `1` to `100`).

## Forwarding options

Export environment options using `export` command:

```bash
export ZSWAP_ENABLED_VALUE=Y
export ZSWAP_SAME_FILLED_PAGES_ENABLED_VALUE=Y
export ZSWAP_MAX_POOL_PERCENT_VALUE=60
export ZSWAP_COMPRESSOR_VALUE=zstd
export ZSWAP_ZPOOL_VALUE=z3fold
export ZSWAP_ACCEPT_THREHSOLD_PERCENT_VALUE=40
```

Start application with `--env` command-line argument:

```
sudo zswap-cli --env
```
