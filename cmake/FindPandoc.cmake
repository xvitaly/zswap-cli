find_program(
    Pandoc_EXECUTABLE
    NAMES pandoc
    DOC "Pandoc main executable"
)

find_package_handle_standard_args(
    Pandoc
    FOUND_VAR Pandoc_FOUND
    REQUIRED_VARS Pandoc_EXECUTABLE
)

mark_as_advanced(Pandoc_EXECUTABLE)
