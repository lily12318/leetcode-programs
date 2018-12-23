#include <iostream>
#include <vector>

using namespace std;

// My answer: recursive
/*
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> Output;

		if (nums.size() == 1)
		{
			Output.push_back(nums);
			return Output;
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			vector<int> InputNums = nums;
			InputNums.erase(InputNums.begin() + i);
			vector<vector<int>> Temp = permute(InputNums);
			for (int k = 0; k < Temp.size(); ++k)
			{
				Temp[k].insert(Temp[k].begin(), nums[i]);
				Output.push_back(Temp[k]);
			}			
		}
		return Output;
	}
};*/

// better answer :dfs
class Solution {
public:
	void dfs(const vector<int>& vNums, vector<bool>& vioIsUsed, vector<int>& vioCur, vector<vector<int>>& voResult)
	{
		if (vioCur.size() == m_num)
		{
			voResult.push_back(vioCur);
			return;
		}
		for (int i = 0; i < vNums.size(); ++i)
		{
			if (vioIsUsed[i] == true) continue;
			vioIsUsed[i] = true;
			vioCur.push_back(vNums[i]);
			dfs(vNums, vioIsUsed, vioCur, voResult);
			vioCur.pop_back();
			vioIsUsed[i] = false;
		}
		return;
	}

	vector<vector<int>> permute(vector<int>& nums) {
		m_num = nums.size();
		vector<vector<int>> Result;
		vector<bool> UsedTag(m_num, false);
		vector<int> Cur;
		dfs(nums, UsedTag, Cur, Result);
		return Result;
	}
private:
	int m_num;

};


void main()
{
	vector<int> Input = { 1, 2, 3 };
	Solution solution;
	vector<vector<int>> OutPut = solution.permute(Input);
	for (int i = 0; i < OutPut.size(); ++i)
	{
		for (int k = 0; k < OutPut[0].size(); ++k)
			cout << OutPut[i][k] << ",";
		cout << endl;
	}
}