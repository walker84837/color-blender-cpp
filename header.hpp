#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <string>

class ColorBlender {
public:
	struct Color {
		int red;
		int green;
		int blue;

		Color() : red(0), green(0), blue(0) {} // Default constructor

		Color(int r, int g, int b) : red(r), green(g), blue(b) {}
	};

	static std::vector<std::string> blendColors(const std::string& startColor, const std::string& endColor, int precision) {
		Color start = parseHexColor(startColor);
		Color end = parseHexColor(endColor);

		int count = precision + 2; // Number of colors including start and end

		std::vector<Color> palette(count);
		palette[0] = start;
		palette[count - 1] = end;

		for (int i = 1; i < count - 1; i++) {
			int r = start.red + ((end.red - start.red) * i) / (count - 1);
			int g = start.green + ((end.green - start.green) * i) / (count - 1);
			int b = start.blue + ((end.blue - start.blue) * i) / (count - 1);
			palette[i] = Color(r, g, b);
		}

		std::vector<std::string> blendedColors;
		for (const auto& color : palette) {
			blendedColors.push_back(colorToHex(color));
		}

		std::sort(blendedColors.begin(), blendedColors.end());

		return blendedColors;
	}

private:
	static Color parseHexColor(const std::string& hexColor) {
		int r, g, b;
		std::istringstream(hexColor.substr(1, 2)) >> std::hex >> r;
		std::istringstream(hexColor.substr(3, 2)) >> std::hex >> g;
		std::istringstream(hexColor.substr(5, 2)) >> std::hex >> b;

		return Color(r, g, b);
	}

	static std::string colorToHex(const Color& color) {
		std::stringstream ss;
		ss << "#" << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << color.red
		   << std::setw(2) << color.green << std::setw(2) << color.blue;
		return ss.str();
	}
};

std::string toLowercase(const std::string& input) {
	std::string lowercaseString = input;
	std::transform(lowercaseString.begin(), lowercaseString.end(), lowercaseString.begin(),
				   [](unsigned char c) { return std::tolower(c); });
	return lowercaseString;
}