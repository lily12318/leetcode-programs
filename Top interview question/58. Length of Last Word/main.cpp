#include<iostream>
#include <sstream>

using namespace std;

class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		if (s.empty()) return 0;
		int Count = 0;
		int Idx = s.size()-1;
		for (; Idx >= 0; --Idx)
		{
			if (s[Idx] == ' ')
			{
				if (Count > 0) break;
				continue;
			}
			++Count;
		}
		return Count;
	}
};

int main()
{
	string s;
	getline(cin, s);
	
	Solution solution;
	cout << solution.lengthOfLastWord(s) << endl;
	return 0;
}