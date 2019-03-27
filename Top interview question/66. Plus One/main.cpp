#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		bool carry = true;
		int Idx = digits.size() - 1;
		while (carry && (Idx>=0))
		{
			carry = ++digits[Idx] / 10;
			digits[Idx--] %= 10;
		}
		if (Idx <= 0 && carry) digits.insert(digits.begin(), 1);
		return digits;
	}
};

int main()
{
	vector<int> Digits;
	
	int ch;
	while (cin >> ch)
	{
		Digits.push_back(ch);
	}
	
	Solution solution;
	solution.plusOne(Digits);

	for (int i = 0; i < Digits.size(); ++i)
	{
		cout << Digits[i] << ' ';
	}
	cout << endl;
	return 0;
}