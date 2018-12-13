#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int Sign = 1;
		int Start = 0;
		int Value = 0;
		while (str[Start] == ' ') Start++;
		if (str[Start] == '-')
		{
			Sign = -1;
			Start++;
		}
		else if (str[Start] == '+')
		{
			Sign = 1;
			Start++;
		}
		for (int i = Start; i < str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				if (Value > INT_MAX / 10 || (Value == INT_MAX / 10 && str[i] > '7')) return INT_MAX;
				else if (Value < INT_MIN/10 || (Value == INT_MIN/10 && str[i] > '8'))return INT_MIN;
				else
					Value = Value * 10 + Sign*(str[i] - 48);
			}
			else break;
		}
		return Value;
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
		string str = stringToString(line);

		int ret = Solution().myAtoi(str);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}