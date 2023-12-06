# color-blender-cpp

A color blending utility in C++ that blends two hexadecimal colors with a user-defined number of midpoints.

## Table of Contents

1.  [Usage](#usage)
2.  [Contributing](#contributing)
3.  [License](#license)

## Usage

To use the color blender, follow the steps below:

1.  Clone the repository: `git clone https://github.com/walker84837/color-blender-cpp.git`.
2.  Open a terminal or command prompt and navigate to the project directory.
3.  Compile the code by using `make`. To clean build artifacts, do `make clean`.

<!-- end list -->

  - `./color-blender <first-color> <second-color> <midpoints> <write-to-file>`
      - `<first-color>`: the first hexadecimal color
      - `<second-color>`: the second hexadecimal color
      - `<midpoints>`: the number of midpoints
      - `<write-to-file>`: the possible values are "yes" or "no". They indicate whether to write the blended colors to "output.txt".

## Contributing

Contributions to the `color-blender-cpp` project are always welcome. If you would like to contribute, please follow the following guidelines:

  - Follow the [Linux kernel coding style](https://docs.kernel.org/process/coding-style.html#codingstyle). Don't keep the lines exactly 80 characters long (eg. don't break string literals in different parts).
  - Keep your changes C++17. Prefer standard functions over reinventing the wheel. Feel free to replace functions with ones which use standard functions. Make sure to keep the same parameters.
  - Open an issue if you are proposing bigger changes (eg. using a new library for X feature, changing styles, removing `using` statements). In your issue please describe the following:
      - give more information about your proposed changes,
      - the reasoning behind them,
      - what's the difference between not applying them and applying them.

Thank you for your contributions!

## License

This project is released under the [GNU General Public License, version 3](LICENSE.md).
