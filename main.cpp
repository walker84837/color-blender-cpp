#include <iostream>
#include <fstream>
#include <vector>
#include "header.hpp"

int main(int argc, char* argv[]) {
	int midpoints;
	bool shouldWrite;
	std::string startColor;
	std::string endColor;
	std::string temp;

	/*
		Why the fuck is there `argv[1] == nullptr`?
		Well, because if the first argument is null,
		then, there isn't any second argument, not
		a third one, and so on. I know this isn't
		used by so many developers, but I wanna be
		different.
	*/

	if (argv[1] == nullptr) {
		std::cout << "What is the first color?" << std::endl << "> ";
		std::cin >> startColor;
		std::cout << "What is the second color?" << std::endl << "> ";
		std::cin >> endColor;
		std::cout << "How many midpoints?" << std::endl << "> ";
		std::cin >> midpoints;
		std::cout << "Should the blended colors be written to a file? (yes|no)" << std::endl << "> ";
		std::cin >> temp;
	}

	else if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
		std::cout << argv[0] << " <first color> <second color> <midpoints> <write to file? yes|no>" << std::endl;
		std::cout << "Color blender - Blends 2 hex colors with a user-given amount of midpoints." << std::endl;
		return 0;
	}

	else if (argc == 5) {
		startColor = std::string(argv[1]);
		endColor = std::string(argv[2]);
		midpoints = std::stoi(std::string(argv[3]));
		temp = std::string(argv[4]);
	}

	else {
		std::cerr << "Invalid input. Try again." << std::endl;
		return 1;
	}

	if (toLowercase(temp) == "yes") {
		shouldWrite = true;
	}

	else if (toLowercase(temp) == "no") {
		shouldWrite = false;
	}

	else {
		std::cerr << "Input is invalid. Input taken as a \"no\"." << std::endl;
		shouldWrite = false;
	}

	std::vector<std::string> blendedColors = ColorBlender::blendColors(startColor, endColor, midpoints);

	if (!shouldWrite) {
		std::cout << std::endl;
		for (const auto& color : blendedColors) {
			std::cout << color << std::endl;
		}
		std::cout << std::endl;
	}

	else {
		std::ofstream output("output.txt");
		if (output.is_open()) {
			for (const auto& color : blendedColors) {
				output << color << std::endl;
			}
			output.close();
			std::cout << "File 'output.txt' written successfully." << std::endl;
		} else {
			std::cerr << "Error opening the file 'output.txt' for writing." << std::endl;
			return 1;
		}
	}

	return 0;
}
