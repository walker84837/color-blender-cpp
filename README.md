# color-blender-cpp

A simple color blending utility in C++ that blends two hexadecimal colors with a user-defined number of midpoints. The blended colors can be optionally written to a file.

## Table of Contents

1. [Usage](#usage)
2. [Contributing](#contributing)
3. [License](#license)

## Usage

To use the color blender, follow the steps below:

1. Clone the repository:
  ```git clone https://github.com/walker84837/color-blender-cpp.git```.

2. Ensure you have a C++ compiler installed on your system.

3. Open a terminal or command prompt and navigate to the project directory.

4. Compile the code using the following command:
  ```make```
  To remove the executable file, do:
  ```make clean```

5. Run the executable with the desired arguments. There are two ways to provide the input:
   ```./color-blender <first-color> <second-color> <midpoints> <write-to-file>```

   Replace `<first-color>` with the first hexadecimal color, `<second-color>` with the second hexadecimal color, `<midpoints>` with the number of midpoints (an integer), and `<write-to-file>` with either "yes" or "no" to indicate whether to write the blended colors to a file.

6. The program will blend the colors and display the result. If you chose to write the blended colors to a file, it will be saved in a file named `output.txt` in the current directory.

## Contributing

Contributions to the color-blender-cpp project are always welcome. If you would like to contribute, please follow these steps:

1. Fork the repository on GitHub.

2. Create a new branch for your changes.

3. Make your modifications, add new features, or fix bugs. (Ensure your code is well-tested and documented).

4. Commit your changes and push them to your forked repository.

5. Submit a pull request to forked repository, describing your changes.

Thank you for your contributions!

## License

This project is released under the GNU GPLv3. You can find more details in the [LICENSE](LICENSE.md) file.

