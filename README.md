# zswap-cli

## About

Zswap-cli is a command-line tool to control the zswap kernel module options on the fly.

Zswap is a compressed cache for swap pages. It takes pages that are in the process of being swapped out to disk and tries to compress them into a RAM-based memory pool with dynamic allocation.

It trades CPU cycles for a significant performance boost since reading from a compressed cache is much faster than reading from a swap device.

## Features

Currently supported features:

  * CLI, environment variables and configuration files support.
  * Optional systemd integration.
  * Usage statistics and debug information support.

## License

This project is licensed under the terms of the [MIT license](LICENSE).

## Documentation

Documentation is available [here](docs/README.md).
