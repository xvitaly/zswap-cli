% zswap-cli(1) | General Commands Manual

# NAME

zswap-cli - command-line tool to control ZSwap Linux kernel module

# SYNOPSIS

**zswap-cli** [**OPTION**...]

# DESCRIPTION

ZSwap-cli is a simple command-line tool to control ZSwap Linux kernel module.

# COMMAND-LINE OPTIONS

#### \-\-env
Get options from environment variables instead of cmdline.

#### \-\-stats
Get statistics and current settings of ZSwap kernel module.

Supported values:

  * `0` - print both ZSwap kernel module settings and debug information;
  * `1` - print ZSwap kernel module settings;
  * `2` - print ZSwap kernel module usage summary;
  * `3` - print  ZSwap kernel module debug information.

#### -e, \-\-enabled
Enable or disable ZSwap kernel module.

#### -s, \-\-same_filled_pages_enabled
Enable or disable memory pages deduplication.

#### -p, \-\-max_pool_percent
The maximum percentage of memory that the compressed pool can occupy.

#### -c, \-\-compressor
The default comression algorithm.

#### -z, \-\-zpool
The kernel's zpool type.

#### -a, \-\-accept_threhsold_percent
The threshold at which ZSwap would start accepting pages again after it became full.

#### -h, \-\-help
Print help message and exit.

# ENVIRONMENT OPTIONS

ZSwap-cli support of getting options from environment variables.

## Supported options

  * **ZSWAP_ENABLED_VALUE** - enable (**Y**) or disable (**N**) ZSwap kernel module.
  * **ZSWAP_SAME_FILLED_PAGES_ENABLED_VALUE** - enable (**Y**) or disable (**N**) memory pages deduplication.
  * **ZSWAP_MAX_POOL_PERCENT_VALUE** - the maximum percentage of memory that the compressed pool can occupy (integer from **1** to **100**).
  * **ZSWAP_COMPRESSOR_VALUE** - the default comression algorithm.
  * **ZSWAP_ZPOOL_VALUE** - the kernel's zpool type.
  * **ZSWAP_ACCEPT_THREHSOLD_PERCENT_VALUE** - the threshold at which ZSwap would start accepting pages again after it became full (integer from **1** to **100**).

## Forwarding options

Export environment options using `export` command:

```
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

# EXIT STATUS

0: Successful exit.

1: Insuffient access rights.

# SYSTEMD UNIT

After installation, the systemd-unit **zswap-cli.service** will be added.

## Changing settings

All settings are stored in **/etc/zswap-cli.conf** file. It use environment options syntax.

## Enabling unit

Enable systemd-unit and run it on system startup:

```
sudo systemctl enable --now zswap-cli.service
```

## Disabling unit

Disable systemd-unit and stop runing it on system startup:

```
sudo systemctl disable zswap-cli.service
```

## Running unit

You can also run systemd-unit without adding it to startup.

Start unit and enable ZSwap:

```
sudo systemctl start zswap-cli.service
```

Stop unit and disable ZSwap:

```
sudo systemctl stop zswap-cli.service
```

# AUTHORS

Vitaly Zaitsev ⟨vitaly@easycoding.org⟩.
