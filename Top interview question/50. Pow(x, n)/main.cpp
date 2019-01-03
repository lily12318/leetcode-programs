#include <iostream>

//My answer
/*
class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0) return 1;
		long long Count = 1;
		double PowValue = x;
		int Num = std::abs(n);
		while (2 * Count <= Num)
		{
			PowValue = PowValue * PowValue;
			Count *= 2;
		}
		return n > 0 ? PowValue * myPow(x, Num - Count) : 1/PowValue * myPow(x, Count - Num);
	}
};*/

//better answer：二分法
class Solution {
public:
	double myPow(double x, int n) {
		long long N = n;
		if (N < 0) {
			x = 1 / x;
			N = -N;
		}
		double ans = 1;
		double current_product = x;
		for (long long i = N; i; i /= 2) {
			if ((i % 2) == 1) {
				ans = ans * current_product;
			}
			current_product = current_product * current_product;
		}
		return ans;
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
	std::cout << InputValue << "'s " << InputN << "次方为：" << Ret << std::endl;
}