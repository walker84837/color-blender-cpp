#include "header.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

int main(int argc, char *argv[]) {
	ColorBlender *blender = new ColorBlender;
	int midpoints = 10;
	bool shouldWrite = false;
	std::string startColor;
	std::string endColor;
	std::string shouldWrite_inp;

	try {
		if (argv[1] == nullptr) {
			throw std::invalid_argument(
			    "Insufficient arguments provided.");
		}
	} catch (std::invalid_argument &error) {
		std::cerr << "Error while parsing arguments: " << error.what();
		return 1;
	}

	if (std::strcmp(argv[1], "--help") == 0 ||
	    std::strcmp(argv[1], "-h") == 0) {
		std::cout << "Usage: " << argv[0]
			  << " <first color> <second color> [<midpoints>] "
			     "[<write to file? yes|no>]"
			  << '\n';
		std::cout << "Color blender - Blends 2 hex colors with a "
			     "user-given amount of midpoints."
			  << '\n';
		return 0;
	}

	if (argc >= 3) {
		startColor = std::string(argv[1]);
		endColor = std::string(argv[2]);
	}

	if (argc >= 4) {
		midpoints = std::stoi(std::string(argv[3]));
	}

	if (argc >= 5) {
		shouldWrite_inp = std::string(argv[4]);
		if (toLowercase(shouldWrite_inp) == "yes") {
			shouldWrite = true; // Set to true if "yes" is provided
		}
	}

	std::vector<std::string> blendedColors =
	    blender->blendColors(startColor, endColor, midpoints);

	if (!shouldWrite) {
		for (const std::string &color : blendedColors) {
			std::cout << color << '\n';
		}
	} else {
		try {
			std::ofstream output("output.txt");
			if (output.is_open()) {
				for (const std::string &color : blendedColors) {
					output << color << '\n';
				}
				output.close();
				std::cout
				    << "File 'output.txt' written successfully."
				    << '\n';
			} else {
				throw std::runtime_error(
				    "Caught an exception while writing to "
				    "'output.txt'");
			}
		} catch (std::runtime_error &error) {
			std::cerr << "Error while writing the file: "
				  << error.what();
			return 1;
		}
	}

	delete blender;

	return 0;
}
