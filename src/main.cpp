#include <vector>
#include "common.hpp"
#include "header.hpp"
#include "wrappers.hpp"

using std::vector;

int main(int argc, char *argv[]) {
	ColorBlender blender;
	int midpoints = 10;
	bool shouldWrite = false;
	string startColor = "#000000";
	string endColor = "#000000";

	if (argc < 2 || argc < 3 || wrappers::streq(std::string_view(argv[1]), "--help")) {
		std::cout << "Usage: " << argv[0] << " <first color> <second color> [<midpoints>] [<write to file? yes|no>]" << '\n';
		std::cout << "color-blender-cpp 0.1.1 - Blends 2 hex colors with a user-given amount of midpoints." << '\n';
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
		string shouldWrite_inp = string(argv[4]);
		if (utilities::toLowercase(shouldWrite_inp) == "yes") {
			shouldWrite = true;
		}
	}

	vector<string> blendedColors = blender.blendColors(startColor, endColor, midpoints);

	if (!shouldWrite) {
		for (const string &color : blendedColors) {
			std::cout << color << std::endl;
		}
	}

	else {
		std::ofstream output("output.txt");
		if (output.is_open()) {
			for (const string &color : blendedColors) {
				output << color << '\n';
			}
			output.close();
			std::cout << "File 'output.txt' written successfully." << std::endl;
		}

		else {
			std::cerr << "Something went wrong while trying to write the results to the output file." << std::endl;
			return 1;
		}
	}

	return 0;
}
