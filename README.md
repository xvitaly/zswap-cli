# zswap-cli

[![GitHub version](https://img.shields.io/github/v/release/xvitaly/zswap-cli?sort=semver&color=brightgreen&logo=git&logoColor=white)](https://github.com/xvitaly/zswap-cli/releases)
[![Fedora CI](https://github.com/xvitaly/zswap-cli/actions/workflows/fedora.yml/badge.svg)](https://github.com/xvitaly/zswap-cli/actions/workflows/fedora.yml)
[![Ubuntu CI](https://github.com/xvitaly/zswap-cli/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/xvitaly/zswap-cli/actions/workflows/ubuntu.yml)
[![CodeQL](https://github.com/xvitaly/zswap-cli/actions/workflows/codeql.yml/badge.svg)](https://github.com/xvitaly/zswap-cli/actions/workflows/codeql.yml)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/ac63a5d2c5664086952baf93f72085e9)](https://www.codacy.com/gh/xvitaly/zswap-cli/dashboard)
[![CodeFactor](https://www.codefactor.io/repository/github/xvitaly/zswap-cli/badge)](https://www.codefactor.io/repository/github/xvitaly/zswap-cli)
[![GitHub issues](https://img.shields.io/github/issues/xvitaly/zswap-cli.svg?label=issues&maxAge=180)](https://github.com/xvitaly/zswap-cli/issues)
---

## About

Zswap-cli is a command-line tool to control [zswap](https://www.kernel.org/doc/html/latest/admin-guide/mm/zswap.html) Linux kernel module options.

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
