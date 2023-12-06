# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/),
and this project adheres to [Semantic Versioning](https://semver.org/).

## \[Unreleased\]

## \[0.1.2\] - 2023-12-06

### Added

  - User input is sanitized by stripping every non-hex character and padding it with zeroes if the resulting string isn't 6 characters long.

### Changed

  - Changed naming style to snake_case for better readability.

## \[0.1.1\] - 2023-11-08

### Changed

  - Optimized the `streq` function. 

## \[0.1.0\] - 2023-11-01

### Added

  - Added the folders: `docs/`, `include/` and `src/`.

### Fixed

  - None.

### Changed

  - None.

### Removed

  - None.

## \[0.0.3\] - 2023-07-22

### Added

  - Last two command-line arguments are optional:
      - Midpoints: default is `10`
      - Write to file or not: default is `false`

### Fixed

  - Exceptions are now caught properly, instead of being uncaught.

## \[0.0.2\] - 2023-06-24

### Added

  - Providing no arguments now throws an error, making the user give values in the command line.
  - Added Doxygen documentation
  - Added `.vscode/` and `color-blender` to the `.gitignore`

### Fixed

  - Corrected license in README.md (Unlicense -\> GNU GPLv3)
  - Downloaded Markdown version of LICENSE

## \[0.0.1\] - 2023-??-??

### Added

  - First release of `color-blender-cpp`.

### Fixed

  - None.

