#
# SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

find_package(Git REQUIRED)

execute_process(
    COMMAND ${GIT_EXECUTABLE} describe --tags --always HEAD
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE _git_commit_version
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
)

execute_process(
    COMMAND ${GIT_EXECUTABLE} show --no-patch --no-notes --format=%as HEAD
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE _git_commit_date
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
)

execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE _git_commit_hash
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
)

string(SUBSTRING "${_git_commit_version}" 1 -1 SNAPSHOT_RELEASE_VERSION)

set(SNAPSHOT_RELEASE_DATE "${_git_commit_date}")
set(SNAPSHOT_RELEASE_URL "${CMAKE_PROJECT_HOMEPAGE_URL}/commit/${_git_commit_hash}")

unset(_git_commit_version)
unset(_git_commit_date)
unset(_git_commit_hash)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    SnapshotRelease
    REQUIRED_VARS SNAPSHOT_RELEASE_VERSION SNAPSHOT_RELEASE_DATE SNAPSHOT_RELEASE_URL
    REASON_FAILURE_MESSAGE "Failed to retrieve the required snapshot release data!"
)
