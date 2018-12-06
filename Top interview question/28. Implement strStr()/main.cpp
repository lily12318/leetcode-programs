#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0)
			return 0;
		int i = 0;
		for (; i < haystack.size(); i++)
		{
			if (haystack.size() - i < needle.size()) return -1;
			if (haystack[i] == needle[0])
			{
				int k = i + 1;
				int j = 1;
				for (; j < needle.size(); j++, k++)
				{
					if (haystack[k] != needle[j])
						break;
				}
				if (j == needle.size())
				{
					return k - needle.size();
				}
			}
		}
		return -1;
	}
};

string stringToString(string input) {
	_ASSERTE(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	string line;
	while (getline(cin, line)) {
		string haystack = stringToString(line);
		getline(cin, line);
		string needle = stringToString(line);

		int ret = Solution().strStr(haystack, needle);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}