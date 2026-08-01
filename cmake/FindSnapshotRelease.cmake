#
# SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

find_package(Git REQUIRED)

execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE _git_commit_hash
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
)

set(SNAPSHOT_RELEASE_HASH "${_git_commit_hash}")
unset(_git_commit_hash)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    SnapshotRelease
    REQUIRED_VARS SNAPSHOT_RELEASE_HASH
    REASON_FAILURE_MESSAGE "Failed to retrieve the commit hash from Git!"
)
