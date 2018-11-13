#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int MaxStart = 0;
		int MaxEnd = 0;
		int MaxLen = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int Len1 = findMaxLen(i, i, s);
			int Len2 = findMaxLen(i, i + 1, s);
			int Len = Len1 > Len2 ? Len1 : Len2;
			if (MaxLen < Len)
			{
				MaxLen = Len;
				MaxStart = i - (MaxLen - 1) / 2;
				MaxEnd = i + MaxLen / 2;
			}
		}
		return s.substr(MaxStart, MaxLen);
	}

	int findMaxLen(int i, int j, string s)
	{
		while (i >= 0 && j < s.size() && s[i] == s[j])
		{
			i--;
			j++;
		}
		return j - i - 1;
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

		string ret = Solution().longestPalindrome(s);

		string out = (ret);
		cout << out << endl;
	}
	return 0;
}