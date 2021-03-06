#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int i = 0;
		int MaxLen = 0;
		unordered_map<char, int> SubString;

		for (int j = i; j < s.size(); j++)
		{
			auto iter = SubString.find(s[j]);
			if (iter != SubString.end())
				i = iter->second > i ? iter->second : i;
			MaxLen = MaxLen > (j - i + 1) ? MaxLen : (j - i + 1);
			if (iter == SubString.end())
				SubString.insert(make_pair(s[j], j + 1));
			else
				iter->second = j + 1;
		}
		return MaxLen;
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
		string s = stringToString(line);

		int ret = Solution().lengthOfLongestSubstring(s);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}