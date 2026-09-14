# Notes for package maintainers

## Packaging recommendations

Please always include the configuration file in your package (default or custom), as it is now required for using the `--system` command-line option and the systemd unit.

Please do not disable core features without a compelling reason, as this will degrade the user experience.

## Custom configuration file

Distributions can include a custom [configuration file](configuration-files.md) without the need of patching the default one. This file can be specified by using the `-DCUSTOM_CONFIG_FILE_PATH:FILEPATH=/path/to/custom.conf` [configuration option](installation.md).

## Custom release information

Distributions can include a custom suffix to the project version number by using the `-DCUSTOM_RELEASE_INFO:STRING="custom"` [configuration option](installation.md). The string specified there will be included in the `--version` output, separated by a hyphen.

## Directories and files ownership

Please remember to include in your package the `$prefix/etc/zswap-cli` directory and a virtual (does not exist by default, but can be created by the user) `$prefix/etc/zswap-cli/system.conf` file to ensure that the package contents are correctly tracked or removed by the package manager.

## Snapshot releases

If you are building a Git snapshot, please use the `-DINCLUDE_COMMIT_HASH:BOOL=ON` [configuration option](installation.md) to include the commit hash in the `--version` output.

For the official release builds, this option should not be enabled.
