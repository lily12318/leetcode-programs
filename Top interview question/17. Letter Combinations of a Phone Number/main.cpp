#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<vector<string>> letter = { {""}, {"a","b","c"}, {"d","e","f"}, {"g","h","i"}, {"j","k","l"}, {"m","n","o"}, {"p","q","r","s"}, {"t","u","v"}, {"w","x","y","z"} };
		vector<string> LetterCombinations;
		if (digits.size() == 0)	return LetterCombinations;
		if (digits.size() == 1)
		{
			return letter[int(digits[0])-48-1];
		}
		vector< vector<string> > letter_A;
		vector< vector<string> > letter_B;
		letter_A.push_back(letter[digits[0]-48-1]);
		for (size_t i = 1; i < digits.size(); i++)
			letter_B.push_back(letter[digits[i]-48-1]);
		vector< vector<string> > TempCombinations = findCombinations(letter_A, letter_B);
		for (size_t k = 0; k < TempCombinations.size(); k++)
		{
			string Line;
			for (size_t j = 0; j < TempCombinations[k].size(); j++)
			{
				Line += TempCombinations[k][j];
			}
			LetterCombinations.push_back(Line);
		}
		return LetterCombinations;
	}

	vector< vector<string> > findCombinations(vector< vector<string> > vA, vector< vector<string> > vB)
	{
		vector< vector<string> > Combinations;
		_ASSERTE(vA.size() == 1);
		if (vB.size() == 1)
		{
			for (size_t i = 0; i < vA[0].size(); i++)
			{
				for (size_t k = 0; k < vB[0].size(); k++)
				{
					vector<string> Line = { vA[0][i], vB[0][k] };
					Combinations.push_back(Line);
				}
			}
		}
		else
		{
			vector< vector<string> > vB_first(vB.begin(), vB.begin()+1);
			vector< vector<string> > vB_rest(vB.begin()+1, vB.end());
			Combinations = findCombinations(vA, findCombinations(vB_first, vB_rest));
		}
		return Combinations;
	}
};
*/

//rude traversing
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		if (digits == "")
			return ret;

		ret.push_back("");

		vector<string> dict = { "","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

		for (int i = 0; i < digits.size(); i++)
		{
			int size = ret.size();
			for (int j = 0; j < size; j++)
			{
				string cur = ret[0];
				ret.erase(ret.begin());
				for (int k = 0; k < dict[digits[i] - '0'].size(); k++)
				{
					ret.push_back(cur + dict[digits[i] - '0'][k]);
				}
			}
		}
		return ret;
	}
};


void main()
{
	std::string _str = "23";
	Solution s1;
	vector<string>_nums;
	_nums = s1.letterCombinations(_str);

	for (size_t i = 0; i < _nums.size(); i++)
	{
		std::cout << _nums[i] << ",";
	}
	system("pause");
}