#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		//Ô½½ç
		if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
			return INT_MAX;
		int Sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
		long long LDividend = abs((long long)dividend);
		long long LDivisor = abs((long long)divisor);
		if (LDivisor == 1)
			return divisor > 0 ? dividend : -dividend;

		int Res = 0;
		while (LDividend >= LDivisor)
		{
			long long Temp1 = LDividend;
			long long Temp2 = LDivisor;
			int Count = 1;
			while (Temp1 >= Temp2 << 1)
			{
				Temp2 <<= 1;
				Count <<= 1;
			}
			LDividend -= Temp2;
			Res += Count;
		}
		return Res*Sign;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int dividend = stringToInteger(line);
		getline(cin, line);
		int divisor = stringToInteger(line);

		int ret = Solution().divide(dividend, divisor);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}