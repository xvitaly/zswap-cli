# Notes for package maintainers

## Build recommendations

If your distribution has standard build flags, the project should use them. Otherwise, we recommend the following:

```sh
export CXXFLAGS="-O2 -fexceptions -fPIC -pipe -Wall -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=2 -D_GLIBCXX_ASSERTIONS -fasynchronous-unwind-tables -fstack-protector-strong -fcf-protection"
```

We also recommend using the `RelWithDebInfo` build configuration to include debug information, which is very useful for obtaining high-quality stack traces when reporting bugs.

## Packaging recommendations

Please always include a configuration file (default or custom) in your package, as it is now required for using the `--system` command-line option and the systemd unit.

Please do not disable core features without a compelling reason, as this will degrade the user experience.

## Custom configuration file

Distributions can include a custom [configuration file](configuration-files.md) without the need of patching the default one. This file can be specified by using the `-DCUSTOM_CONFIG_FILE_PATH:FILEPATH=/path/to/custom.conf` [configuration option](installation.md).

The default configuration file will also be installed, but with the `.example` extension for documentation purposes.

## Custom release information

Distributions can include a custom suffix to the project version number by using the `-DCUSTOM_RELEASE_INFO:STRING="custom"` [configuration option](installation.md). The string specified there will be included in the `--version` output, separated by a hyphen.

## Directories and files ownership

Please remember to include in your package the `$prefix/etc/zswap-cli` directory and a virtual (does not exist by default, but can be created by the user) `$prefix/etc/zswap-cli/system.conf` file to ensure that the package contents are correctly tracked or removed by the package manager.

## Snapshot releases

If you are building a Git snapshot, please use the `-DINCLUDE_COMMIT_HASH:BOOL=ON` [configuration option](installation.md) to include the commit hash in the `--version` output.

For the official release builds, this option should not be enabled.
