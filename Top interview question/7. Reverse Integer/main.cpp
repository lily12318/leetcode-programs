#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int TargetInteger = 0;
		while (x)
		{
			int TempInteger = x % 10;
			x = x / 10;
			if (TargetInteger < INT_MIN / 10 || (TargetInteger == INT_MIN / 10 && TempInteger < -8))
				return 0;
			if (TargetInteger > INT_MAX / 10 || (TargetInteger == INT_MAX / 10 && TempInteger > 7))
				return 0;
			TargetInteger = TargetInteger * 10 + TempInteger;
		}
		return TargetInteger;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int x = stringToInteger(line);

		int ret = Solution().reverse(x);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}