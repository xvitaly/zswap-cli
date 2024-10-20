# Environment options

This project support of getting options from the environment variables.

## Supported options

  * `ZSWAP_ENABLED_VALUE` - enable or disable the ZSwap kernel module.
  * `ZSWAP_SAME_FILLED_PAGES_ENABLED_VALUE` - enable or disable memory pages deduplication.
  * `ZSWAP_MAX_POOL_PERCENT_VALUE` - the maximum percentage of memory that the compressed pool can occupy.
  * `ZSWAP_COMPRESSOR_VALUE` - the algorithm used to compress memory pages.
  * `ZSWAP_ZPOOL_VALUE` - the kernel's zpool type.
  * `ZSWAP_ACCEPT_THRESHOLD_PERCENT_VALUE` - the threshold at which ZSwap would start accepting pages again after it became full.
  * `ZSWAP_NON_SAME_FILLED_PAGES_ENABLED_VALUE` - enable or disable accepting non same filled memory pages.
  * `ZSWAP_EXCLUSIVE_LOADS_VALUE` - enable or disable entries invalidation when memory pages are loaded from compressed pool.
  * `ZSWAP_SHRINKER_ENABLED_VALUE` - enable or disable pool shrinking based on memory pressure.

## Forwarding options

Export the environment variables using the `export` command:

```bash
export ZSWAP_ENABLED_VALUE=Y
export ZSWAP_SAME_FILLED_PAGES_ENABLED_VALUE=Y
export ZSWAP_MAX_POOL_PERCENT_VALUE=60
export ZSWAP_COMPRESSOR_VALUE=lzo
export ZSWAP_ZPOOL_VALUE=z3fold
export ZSWAP_ACCEPT_THRESHOLD_PERCENT_VALUE=90
export ZSWAP_NON_SAME_FILLED_PAGES_ENABLED_VALUE=Y
export ZSWAP_EXCLUSIVE_LOADS_VALUE=Y
export ZSWAP_SHRINKER_ENABLED_VALUE=Y
```

Start the application with the `--env` command-line argument:

```
sudo zswap-cli --env
```

Note that most distributions are configured by default not to pass user-defined ENV settings when using sudo. In such cases, you can explicitly specify them all in one command:

```
sudo ZSWAP_ENABLED_VALUE=Y \
     ZSWAP_SAME_FILLED_PAGES_ENABLED_VALUE=Y \
     ZSWAP_MAX_POOL_PERCENT_VALUE=60 \
     ZSWAP_COMPRESSOR_VALUE=lzo \
     ZSWAP_ZPOOL_VALUE=z3fold \
     ZSWAP_ACCEPT_THRESHOLD_PERCENT_VALUE=90 \
     ZSWAP_NON_SAME_FILLED_PAGES_ENABLED_VALUE=Y \
     ZSWAP_EXCLUSIVE_LOADS_VALUE=Y \
     ZSWAP_SHRINKER_ENABLED_VALUE=Y \
     zswap-cli --env
```
