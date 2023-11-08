#include "common.hpp"

using std::string;
using std::strcmp;

namespace wrappers
{
	bool streq(std::string_view s1, std::string_view s2) {
		return s1.size() == s2.size() && !memcmp(s1.data(), s2.data(), s1.size());
	}
}

namespace utilities
{
	string toLowercase(const std::string &input) {
		string lowercaseString = input;
		std::transform(lowercaseString.begin(), lowercaseString.end(),
				lowercaseString.begin(), [](unsigned char c) {
					return std::tolower(c);
		});
		return lowercaseString;
	}
}
