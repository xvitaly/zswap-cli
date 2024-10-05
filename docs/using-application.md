# Using application

This application can be used in two ways:

  * as a command-line tool;
  * as a systemd unit.

## Using as a CLI tool

### Available command-line options

#### General options

  * `--help` - print help message and exit.
  * `--version` - print version information and exit.

#### Application configuration options

  * `--config` - get options from the [configuration file](configuration-files.md) instead of the cmdline.
  * `--env` - get options from the [environment variables](environment-options.md) instead of the cmdline.
  * `--stats` - show statistics and current settings of the ZSwap kernel module. Supported values:
    * `0` (default) - print everything: kernel module settings, usage summary, and debug information.
    * `1` - print kernel module settings.
    * `2` - print kernel module usage summary.
    * `3` - print kernel module debug information.

#### Kernel module configuration options

  * `-e` or `--enabled` - enable or disable the ZSwap kernel module.
  * `-s` or `--same_filled_pages_enabled` - enable or disable memory pages deduplication.
  * `-p` or `--max_pool_percent` - the maximum percentage of memory that the compressed pool can occupy.
  * `-c` or `--compressor` - the algorithm used to compress memory pages.
  * `-z` or `--zpool` - the kernel's zpool type.
  * `-a` or `--accept_threshold_percent` - the threshold at which ZSwap would start accepting pages again after it became full.
  * `-n` or `--non_same_filled_pages_enabled` - enable or disable accepting non same filled memory pages.
  * `-x` or `--exclusive_loads` - enable or disable entries invalidation when memory pages are loaded from compressed pool.
  * `-r` or `--shrinker_enabled` - enable or disable pool shrinking based on memory pressure.

### Forwarding options

Start the application with at least one command-line argument:

```
sudo zswap-cli --enabled Y --same_filled_pages_enabled Y --max_pool_percent 60 --compressor lzo --zpool z3fold --accept_threshold_percent 40 --non_same_filled_pages_enabled Y --exclusive_loads Y --shrinker_enabled Y
```

## Using with systemd

After [installation](installation.md) with systemd integration enabled, the `zswap-cli.service` unit file will be created.

### Changing settings

All settings are stored in the `/etc/zswap-cli/zswap-cli.conf` file. It uses standard key-value syntax and can be edited by the user.

All supported values can be found [here](configuration-files.md).

### Enabling unit

Enable the systemd unit to allow it to run at system startup:

```
sudo systemctl enable --now zswap-cli.service
```

### Disabling unit

Disable the systemd unit and stop it from running at system startup:

```
sudo systemctl disable zswap-cli.service
```

### Running unit

It is also possible to start the systemd unit without adding it to startup.

Start the unit and enable ZSwap:

```
sudo systemctl start zswap-cli.service
```

Stop the unit and disable ZSwap:

```
sudo systemctl stop zswap-cli.service
```
