#include "common.hpp"

int main(int argc, char *argv[]) {
	ColorBlender blender;
	int midpoints = 10;
	bool shouldWrite = false;
	string startColor;
	string endColor;
	string shouldWrite_inp;

	if (argv[1] == nullptr || argv[2] == nullptr) {
		std::cerr << "Insufficient arguments provided." << '\n';
		return 1;
	}

	if (wrappers::streq(argv[1], "--help")) {
		std::cout << "Usage: " << argv[0] << " <first color> <second color> [<midpoints>] [<write to file? yes|no>]" << '\n';
		std::cout << "Color blender - Blends 2 hex colors with a user-given amount of midpoints." << '\n';
		return 0;
	}

	if (argc >= 3) {
		startColor = string(argv[1]);
		endColor = string(argv[2]);
	}

	if (argc >= 4) {
		midpoints = std::stoi(string(argv[3]));
	}

	if (argc >= 5) {
		shouldWrite_inp = string(argv[4]);
		if (utilities::toLowercase(shouldWrite_inp) == "yes") {
			shouldWrite = true;
		}
	}

	vector<string> blendedColors = blender.blendColors(startColor, endColor, midpoints);

	if (!shouldWrite) {
		for (const string &color : blendedColors) {
			std::cout << color << '\n';
		}
	}

	else {
		std::ofstream output("output.txt");
		if (output.is_open()) {
			for (const string &color : blendedColors) {
				output << color << '\n';
			}
			output.close();
			std::cout << "File 'output.txt' written successfully." << '\n';
		}

		else {
			std::cerr << "Something went wrong while trying to write the results to the output file." << '\n';
			return 1;
		}
	}

	return 0;
}
