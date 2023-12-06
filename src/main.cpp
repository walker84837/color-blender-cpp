#include "common.hpp"
#include "header.hpp"
#include "wrappers.hpp"

using namespace utilities;
using namespace wrappers;

void print_help(char **arguments, string version)
{
	std::cout << "Usage: " << arguments[0] << " <first color> <second color> [<midpoints>] [<write to file? yes|no>]"
		<< std::endl;
	std::cout << "color-blender-cpp " << version << " - Blends 2 hex colors with a user-given amount of midpoints."
		<< std::endl;
}

int main(int argc, char **argv)
{
	const std::string OUTPUT_FILE = "output.txt";
	int midpoints = 10;
	bool should_write = false;
	string start_color;
	string end_color;
	color_blender blender;
	string version = "0.1.2"

	if (argc < 2 || argc < 3 || streq(std::string_view(argv[1]), "--help")) {
		return 0;
	}

	if (argc >= 3) {
		start_color = clean_hex_string(argv[1]);
		end_color = clean_hex_string(argv[2]);
	}

	if (argc >= 4) {
		midpoints = std::stoi(argv[3]);
	}

	if (argc >= 5) {
		string input = to_lowercase(argv[4]);
		if (input == "yes") {
			should_write = true;
		}
	}

	vector<string> blended_colors = blender.blend_colors(start_color,
			end_color, midpoints);

	if (!should_write) {
		for (const string &color : blended_colors) {
			cout << color << endl;
		}
	}

	else {
		std::ofstream output(OUTPUT_FILE);
		if (output.is_open()) {
			for (const string &color : blended_colors) {
				output << color << '\n';
			}
			output.close();
			cout << "File " << quoted(OUTPUT_FILE) <<
				" written successfully." << endl;
		}

		else {
			std::cerr << "Something went wrong while trying to write the results to the " << quoted(OUTPUT_FILE) << " ." << std::endl;
			return 1;
		}
	}

	return 0;
}
