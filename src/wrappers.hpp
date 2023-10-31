#include "common.hpp"

using std::string;
using std::strcmp;

namespace wrappers
{
	bool streq(char* s1, char* s2) {
		int val = strcmp(s1, s2);
		switch(val) {
			case 0:
				return true;
				break;
			default:
				return false;
				break;
		}
	}
}

namespace utilities
{
	string toLowercase(const std::string &input) {
		string lowercaseString = input;
		std::transform(lowercaseString.begin(), lowercaseString.end(), lowercaseString.begin(), [](unsigned char c) {
				return std::tolower(c);
			});
		return lowercaseString;
	}
}
