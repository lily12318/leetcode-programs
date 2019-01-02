#include <iostream>

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0) return 1;
		if (n == 1) return x;
		int Count = 1;
		double PowValue = x;
		while (2 * Count <= n)
		{
			PowValue = PowValue * PowValue;
			Count *= 2;
		}
		return PowValue * myPow(x, n - Count);
	}
};

int main()
{
	double InputValue;
	int InputN;
	std::cout << "please input Value and N:" << std::endl;
	std::cin >> InputValue >> InputN;
	Solution solution;
	double Ret = solution.myPow(InputValue, InputN);
	std::cout << InputValue << "'s " << InputN << "´Î·½Îª£º" << Ret << std::endl;
}