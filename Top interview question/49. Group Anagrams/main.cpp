#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//MY answer
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<string> SortTempSet;
		vector<vector<string>> Output;
		for (int i = 0; i < strs.size(); ++i)
		{
			string Temp = strs[i];
			sort(Temp.begin(), Temp.end());
			bool IsFindFlag = false;
			for (int k = 0; k < SortTempSet.size(); ++k)
			{
				if (Temp == SortTempSet[k])
				{
					IsFindFlag = true;
					Output[k].push_back(strs[i]);
				}
			}
			if (!IsFindFlag)
			{
				vector<string> NewElement = { strs[i] };
				SortTempSet.push_back(Temp);
				Output.push_back(NewElement);
			}

		}
		return Output;
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
			cout << Output[i][k];
		}
		cout << endl;
	}
}