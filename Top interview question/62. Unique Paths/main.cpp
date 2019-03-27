#include <iostream>
#include <vector>
#include <math.h>

class Solution
{
public:
	//My solution1:C(m-1,n-1)ÅÅÁÐ¹«Ê½
// 	int uniquePaths(int m, int n)
// 	{
// 		if (m < 0 || n < 0 ) return -1;
// 		int SumSteps = m + n - 2;
// 		int ChangeSteps = m < n ? m - 1 : n - 1;
// 		double Count = 1;
// 		while (ChangeSteps)
// 		{
// 			Count *= (double)SumSteps-- / ChangeSteps--;
// 		}
// 		return round(Count);
// 	}
	//solution2: DP algorithm
	int uniquePaths(int m, int n)
	{
		int MoreSteps, LessSteps;
		m < n ? (LessSteps = m, MoreSteps = n) : (MoreSteps = m, LessSteps = n);
		std::vector<int> Temp(LessSteps, 1);
		for (int i = 1; i < MoreSteps; ++i)
		{
			for (int j = 1; j < LessSteps; ++j)
			{
				Temp[j] += Temp[j - 1];
			}
		}
		return Temp[LessSteps - 1];
	}
};

int main()
{
	int m, n;
	std::cin >> m >> n;
	Solution solution;
	std::cout << solution.uniquePaths(m, n);

	return 0;
}