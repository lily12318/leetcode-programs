#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	vector< vector<int> > threeSum(vector<int>& nums) {
		vector<int> TargetNum(3);
		vector< vector<int> > TargetArrayNum;

		if (nums.empty() || nums.size() < 3)	return TargetArrayNum;
		sort(nums.begin(), nums.end());
		if (nums[0] > 0 || nums[nums.size() - 1] < 0)	return TargetArrayNum;
		for (size_t i = 0; i < nums.size() - 2; i++)
		{
			if (i > 0 && nums[i] == nums[i-1])
				continue;
			if (nums[i] > 0)
				break;
			int TempSum = 0 - nums[i];
			for (size_t j = i + 1, k = nums.size() - 1; j < k;)
			{
				if (nums[j] + nums[k] == TempSum)
				{
					TargetNum[0] = nums[i];
					TargetNum[1] = nums[j++];
					TargetNum[2] = nums[k--];
					TargetArrayNum.push_back(TargetNum);
					while (j < k && nums[j - 1] == nums[j])
						j++;
					while (j < k && nums[k + 1] == nums[k])
						k--;
				}
				else if (nums[j] + nums[k] < TempSum)
					j++;
				else
					k--;
			}
			while (i < nums.size() - 2 && nums[i] == nums[i + 1])
				i++;
		}
		return TargetArrayNum;
	}
};

int main() {
	int a[] = { 3, 0, -2, -1, 1, 2};
	int len = sizeof(a) / sizeof(a[0]);
	vector<int> num(a, a + len);
	Solution s;
	vector< vector<int> > result;
	result = s.threeSum(num);
	// Êä³ö½á¹û
	for (int q = 0; q < result.size(); q++) {
		vector<int> x = result[q];
		cout << "(";
		int t;
		for (t = 0; t < x.size() - 1; t++) {
			cout << x[t] << " ";
		}
		cout << x[t];
		cout << ")" << endl;
	}

	return 0;
}
