#include "common.hpp"

namespace wrappers
{
	bool streq(std::string_view s1, std::string_view s2) {
		return s1.size() == s2.size() && !memcmp(s1.data(), s2.data(), s1.size());
	}
}

namespace utilities
{
	string to_lowercase(const string &input) {
		string lowercase_string = input;
		std::transform(lowercase_string.begin(), lowercase_string.end(),
				lowercase_string.begin(), [](unsigned char c) {
					return std::tolower(c);
		});
		return lowercase_string;
	}

	string clean_hex_string(const char *input_cstr) {
		string input = input_cstr, result;

		for (char ch : input) {
			if (std::isxdigit(ch)) {
				result += ch;
			}
		}

		result.erase(std::remove(result.begin(), result.end(), '#'), result.end());
		result = result.substr(0, 6);

		while (result.length() < 6) {
			result += '0';
		}

		return result;
	}
}
