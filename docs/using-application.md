# Using application

This application can be used in two ways:

  * as a systemd-unit;
  * as a command-line tool.

## Using with systemd

After [installation](installation.md), the systemd-unit `zswap-cli.service` will be added.

### Changing settings

All settings are stored in `/etc/zswap-cli/zswap-cli.conf` file. Feel free to edit it.

All supported values can be found [here](configuration-files.md).

### Enabling unit

Enable systemd-unit and run it on system startup:

```
sudo systemctl enable --now zswap-cli.service
```

### Disabling unit

Disable systemd-unit and stop runing it on system startup:

```
sudo systemctl disable zswap-cli.service
```

### Running unit

You can also run systemd-unit without adding it to startup.

Start unit and enable ZSwap:

```
sudo systemctl start zswap-cli.service
```

Stop unit and disable ZSwap:

```
sudo systemctl stop zswap-cli.service
```

## Using as CLI

### Available command-line options

#### General options

  * `--help` - print help message and exit.
  * `--version` - print version information and exit.

#### Application configuration options

  * `--config` - get options from the [configuration file](configuration-files.md) instead of the cmdline.
  * `--env` - get options from the [environment variables](environment-options.md).
  * `--stats` - get statistics and current settings of ZSwap kernel module.

#### Kernel module configuration options

  * `-e` or `--enabled` - enable (`Y`) or disable (`N`) ZSwap kernel module.
  * `-s` or `--same_filled_pages_enabled` - enable (`Y`) or disable (`N`) memory pages deduplication.
  * `-p` or `--max_pool_percent` - the maximum percentage of memory that the compressed pool can occupy (integer from `1` to `100`).
  * `-c` or `--compressor` - the default compression algorithm.
  * `-z` or `--zpool` - the kernel's zpool type.
  * `-a` or `--accept_threshold_percent` - the threshold at which ZSwap would start accepting pages again after it became full (integer from `1` to `100`).

### Forwarding options

Start application with at least one command-line argument:

```
sudo zswap-cli --enabled Y --same_filled_pages_enabled Y --max_pool_percent 60 --compressor zstd --zpool z3fold --accept_threshold_percent 40
```
