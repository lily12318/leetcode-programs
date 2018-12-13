#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
/*MySolution 1:
		unordered_map<char, int> RomanMap = { { 'I', 1 },{ 'V', 5 },{ 'X', 10 },{ 'L', 50 },{ 'C', 100 },{ 'D', 500 },{ 'M',1000 } };
		int Temp = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			int Value1 = RomanMap.find(s[i])->second;
			if (i < s.size() - 1)
			{
				int Value2 = RomanMap.find(s[i+1])->second;
				if (Value1 < Value2)
				{
					Temp += (Value2 - Value1);
					i++;
					continue;
				}
			}
			Temp += Value1;
		}
		return Temp;*/

		vector<int> Value(s.size());
		int Temp = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == 'I') Value[i] = 1;
			if (s[i] == 'V') Value[i] = 5;
			if (s[i] == 'X') Value[i] = 10;
			if (s[i] == 'L') Value[i] = 50;
			if (s[i] == 'C') Value[i] = 100;
			if (s[i] == 'D') Value[i] = 500;
			if (s[i] == 'M') Value[i] = 1000;
		}
		for (size_t k = 0; k < s.size(); k++)
		{
			if (k < s.size() - 1)
				if (Value[k] < Value[k + 1])
					Temp -= 2 * Value[k];
			Temp += Value[k];
		}
		return Temp;
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

		int ret = Solution().romanToInt(s);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}