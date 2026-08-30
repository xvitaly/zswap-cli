# Configuration files

This application uses a modern way of storing configuration files for the systemd unit and the `--system` command line option:

  * default read-only config `/usr/share/zswap-cli/zswap-cli.conf`, provided by the application developers or your distribution. Should not be edited, as any changes will be overwritten with each program update.
  * user high-priority config `/etc/zswap-cli/zswap-cli.conf`, which can be created and edited by the user and will override all settings from the default one. Its contents will persist between application updates.

In order to make changes to the configuration file, it need to be copied to the `/etc/zswap-cli` directory first:

```
sudo cp -a /usr/share/zswap-cli/zswap-cli.conf /etc/zswap-cli/zswap-cli.conf
```

Now this file can be edited:
```
sudoedit /etc/zswap-cli/zswap-cli.conf
```

Both configuration files have the same standard key-value syntax.

## Supported options

  * `enabled` - enable or disable the ZSwap kernel module.
  * `same_filled_pages_enabled` - enable or disable memory pages deduplication.
  * `max_pool_percent` - the maximum percentage of memory that the compressed pool can occupy.
  * `compressor` - the algorithm used to compress memory pages.
  * `zpool` - the kernel's zpool type.
  * `accept_threshold_percent` - the threshold at which ZSwap would start accepting pages again after it became full.
  * `non_same_filled_pages_enabled` - enable or disable accepting non same filled memory pages.
  * `exclusive_loads` - enable or disable entries invalidation when memory pages are loaded from compressed pool.
  * `shrinker_enabled` - enable or disable pool shrinking based on memory pressure.

## Forwarding options

### System config

Start the application with the `--system` command-line argument:

```
sudo zswap-cli --system
```

### Custom config

Create a custom configuration file:

```ini
[zswap]
enabled=Y
same_filled_pages_enabled=Y
max_pool_percent=60
compressor=lzo
zpool=zsmalloc
accept_threshold_percent=90
non_same_filled_pages_enabled=Y
exclusive_loads=Y
shrinker_enabled=Y
```

Start the application with the `--config` command-line argument:

```
sudo zswap-cli --config /path/to/zswap-cli.conf
```
