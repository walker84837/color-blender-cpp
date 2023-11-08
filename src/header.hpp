#include "common.hpp"

class ColorBlender {
	  public:
	/**
	 * @brief Struct for the RGB colors.
	 *
	 */
	struct Color {
		int red;
		int green;
		int blue;

		Color() : red(0), green(0), blue(0) {}

		Color(int r, int g, int b) : red(r), green(g), blue(b) {}
	};

	/**
	 * @brief Blends 2 hex colors, given starting, ending color and
	 * midpoints.
	 *
	 * @param startColor First hex color. (e.g. #000000)
	 * @param endColor Ending hex color. (e.g. #ffffff)
	 * @param precision Number of blended colors to be output
	 * @return std::vector<std::string>
	 */
	static vector<string> blendColors(const string &startColor, const string &endColor, int precision)
	{
		Color start = parseHexColor(startColor);
		Color end = parseHexColor(endColor);
	
		// Number of colors including start and end.
		int count = precision + 2;

		vector<Color> palette(count);
		palette[0] = start;
		palette[count - 1] = end;

		for (int i = 1; i < count - 1; i++) {
			int r = start.red + ((end.red - start.red) * i) / (count - 1);
			int g = start.green + ((end.green - start.green) * i) / (count - 1);
			int b = start.blue + ((end.blue - start.blue) * i) / (count - 1);
			palette[i] = Color(r, g, b);
		}

		vector<string> blendedColors;
		for (const auto &color : palette) {
			blendedColors.push_back(colorToHex(color));
		}

		std::sort(blendedColors.begin(), blendedColors.end());

		return blendedColors;
	}

	  private:
	/**
	 * @brief Parses a given hex color and converts it to RGB
	 *
	 * @param hexColor Given hex color.
	 * @return Color
	 */
	static Color parseHexColor(const std::string &hexColor) {
		int r, g, b;
		std::istringstream(hexColor.substr(1, 2)) >> std::hex >> r;
		std::istringstream(hexColor.substr(3, 2)) >> std::hex >> g;
		std::istringstream(hexColor.substr(5, 2)) >> std::hex >> b;

		return Color(r, g, b);
	}

	static std::string colorToHex(const Color &color) {
		std::stringstream ss;
		ss << "#" << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
			<< color.red << std::setw(2) << color.green << std::setw(2) << color.blue;
		return ss.str();
	}
};

