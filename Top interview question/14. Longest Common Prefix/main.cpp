#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		for (int i = 0; i < strs[0].size(); i++)
		{
			for (int k = 1; k < strs.size(); k++)
			{
				if (i == strs[k].size() || strs[k][i] != strs[0][i])
					return strs[0].substr(0, i);
			}
		}
		return strs[0];
	}
};

int main()
{
	//vector<string> Strs = { "flower","flow","flight" };
	vector<string> Strs = { "dog", "racecar", "car" };
	Solution TestSolution;
	string RetStr = TestSolution.longestCommonPrefix(Strs);
	cout << RetStr << endl;
}