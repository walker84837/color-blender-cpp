#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "header.hpp"

int main(int argc, char* argv[]) {
	ColorBlender* blender = new ColorBlender;
	int midpoints;
	bool shouldWrite;
	std::string startColor;
	std::string endColor;
	std::string shouldWrite_inp;

	if (argv[1] == nullptr) {
		throw std::invalid_argument("No arguments are provided.");
	}

	else if (std::strcmp(argv[1], "--help") == 0 || std::strcmp(argv[1], "-h") == 0) {
		std::cout << argv[0] << " <first color> <second color> <midpoints> <write to file? yes|no>" << '\n';
		std::cout << "Color blender - Blends 2 hex colors with a user-given amount of midpoints." << '\n';
		return 0;
	}

	else if (argc == 5) {
		startColor = std::string(argv[1]);
		endColor = std::string(argv[2]);
		midpoints = std::stoi(std::string(argv[3]));
		shouldWrite_inp = std::string(argv[4]);
	}

	else {
		std::cerr << "Invalid input. Try again." << '\n';
		return 1;
	}

	if (toLowercase(shouldWrite_inp) != "yes") {
		shouldWrite = false;
	}

	else {
		shouldWrite = true;
	}

	std::vector<std::string> blendedColors = blender->blendColors(startColor, endColor, midpoints);

	if (!shouldWrite) {
		for (const std::string& color : blendedColors) {
			std::cout << color << '\n';
		}
	}

	else {
		std::ofstream output("output.txt");
		if (output.is_open()) {
			for (const std::string& color : blendedColors) {
				output << color << '\n';
			}
			output.close();
			std::cout << "File 'output.txt' written successfully." << '\n';
		} else {
			throw std::runtime_error("Error opening the file 'output.txt' for writing.");
		}
	}

	delete blender;

	return 0;
}
