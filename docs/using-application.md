# Using application

This application can be used in two ways:

  * as a systemd unit;
  * as a command-line tool.

## Using with systemd

After [installation](installation.md), the systemd unit `zswap-cli.service` will be added.

### Changing settings

All settings are stored in the `/etc/zswap-cli/zswap-cli.conf` file. Feel free to edit it.

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

## Using as CLI

### Available command-line options

#### General options

  * `--help` - print help message and exit.
  * `--version` - print version information and exit.

#### Application configuration options

  * `--config` - get options from the [configuration file](configuration-files.md).
  * `--env` - get options from the [environment variables](environment-options.md).
  * `--stats` - show statistics and current settings of the ZSwap kernel module.

#### Kernel module configuration options

  * `-e` or `--enabled` - enable (`Y`) or disable (`N`) the ZSwap kernel module.
  * `-s` or `--same_filled_pages_enabled` - enable (`Y`) or disable (`N`) memory pages deduplication.
  * `-p` or `--max_pool_percent` - the maximum percentage of memory that the compressed pool can occupy (integer from `1` to `100`).
  * `-c` or `--compressor` - the algorithm used to compress memory pages.
  * `-z` or `--zpool` - the kernel's zpool type.
  * `-a` or `--accept_threshold_percent` - the threshold at which ZSwap would start accepting pages again after it became full (integer from `1` to `100`).

### Forwarding options

Start the application with at least one command-line argument:

```
sudo zswap-cli --enabled Y --same_filled_pages_enabled Y --max_pool_percent 60 --compressor lzo --zpool z3fold --accept_threshold_percent 40
```
