#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//MY answer
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> Str_map;
		vector<vector<string>> Result;
		for (size_t i = 0; i < strs.size(); ++i)
		{
			string SortStr = strs[i];
			sort(SortStr.begin(), SortStr.end());
			auto iter = Str_map.find(SortStr);
			if (iter == Str_map.end())
			{
				vector<string> Temp;
				Temp.push_back(strs[i]);
				Str_map[SortStr] = Temp;
			}
			else
				iter->second.push_back(strs[i]);				
		}
		for (auto iter = Str_map.begin(); iter != Str_map.end(); iter++)
		{
			Result.push_back(iter->second);
		}
		return Result;
	}
};

void main()
{
	vector<string> Input = { "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution solution;
	vector<vector<string>> Output = solution.groupAnagrams(Input);
	for (int i = 0; i < Output.size(); ++i)
	{
		for (int k = 0; k < Output[i].size(); ++k)
		{
			cout << Output[i][k] << " ";
		}
		cout << endl;
	}
}