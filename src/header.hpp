#include "common.hpp"

class color_blender {
	  public:
	/**
	 * @brief Struct for the RGB colors.
	 *
	 */
	struct color {
		int red;
		int green;
		int blue;

		color() : red(0), green(0), blue(0) {}

		color(int r, int g, int b) : red(r), green(g), blue(b) {}
	};

	/**
	 * @brief Blends 2 hex colors, given starting, ending color and
	 * midpoints.
	 *
	 * @param start_color First hex color. (e.g. #000000)
	 * @param end_color Ending hex color. (e.g. #ffffff)
	 * @param precision Number of blended colors to be output
	 * @return std::vector<std::string>
	 */
	static vector<string> blend_colors(const string &start_color, const string &end_color, int precision)
	{
		color start = parse_hex_color(start_color);
		color end = parse_hex_color(end_color);
	
		// Number of colors including start and end.
		int count = precision + 2;

		vector<color> palette(count);
		palette[0] = start;
		palette[count - 1] = end;

		for (int i = 1; i < count - 1; i++) {
			int r = start.red + ((end.red - start.red) * i) / (count - 1);
			int g = start.green + ((end.green - start.green) * i) / (count - 1);
			int b = start.blue + ((end.blue - start.blue) * i) / (count - 1);
			palette[i] = color(r, g, b);
		}

		vector<string> blended_colors;
		for (const auto &color : palette) {
			blended_colors.push_back(color_to_hex(color));
		}

		std::sort(blended_colors.begin(), blended_colors.end());

		return blended_colors;
	}

	  private:
	/**
	 * @brief Parses a given hex color and converts it to RGB
	 *
	 * @param hex_color Given hex color.
	 * @return color
	 */
	static color parse_hex_color(const string &hex_color) {
		int r, g, b;
		std::istringstream(hex_color.substr(1, 2)) >> std::hex >> r;
		std::istringstream(hex_color.substr(3, 2)) >> std::hex >> g;
		std::istringstream(hex_color.substr(5, 2)) >> std::hex >> b;

		return color(r, g, b);
	}

	static string color_to_hex(const color &color) {
		std::stringstream ss;
		ss << "#" << std::hex << std::lowercase << std::setw(2) << std::setfill('0')
			<< color.red << std::setw(2) << color.green << std::setw(2) << color.blue;
		return ss.str();
	}
};
