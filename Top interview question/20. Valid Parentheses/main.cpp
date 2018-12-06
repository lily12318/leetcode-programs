#include <iostream>
#include <string>
#include <assert.h>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.size() % 2)	return false;
		unordered_map<char, int> Unordered_Map = { {'(', 0}, {')',1}, {'[', 2}, {']', 3}, {'{', 4}, {'}', 5} };
		stack<char> Stack;

		for (size_t i = 0; i < s.size(); i++)
		{
			int CurValue = Unordered_Map.find(s[i])->second;
			int StackTopValue = Stack.empty() ? -2 : Unordered_Map.find(Stack.top())->second;
			if (CurValue % 2) //ÅÐ¶ÏÊÇ·ñÎªÓÒÀ¨ºÅ
			{
				if (CurValue == StackTopValue + 1)
					Stack.pop();
				else
					return false;
			}
			else
				Stack.push(s[i]);
		}
		if (Stack.empty())
			return true;
		return false;
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
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

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);

		bool ret = Solution().isValid(s);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}