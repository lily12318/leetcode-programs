#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

	//My first answer
	/*
	string countAndSay(int n) {
		if (n == 1) { return "1"; }
		else
		{
			string TargetStr;
			string PreStr = countAndSay(n - 1);
			int Count = 1;
			int CurNum = PreStr[0] - '0';
			int NextNum;
			for (int i = 1; i < PreStr.size(); ++i)
			{
				NextNum = PreStr[i] - '0';
				if (CurNum == NextNum) Count++;
				else
				{
					string CountStr = to_string(Count);
					string NumStr = to_string(CurNum);
					TargetStr += (CountStr + NumStr);
					Count = 1;
				}
				CurNum = NextNum;
			}
			string CountStr = to_string(Count);
			string NumStr = to_string(CurNum);
			TargetStr += (CountStr + NumStr);
		return TargetStr;
		}
	}*/

	//My second Answer
	string countAndSay(int n)
	{

	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int n = stringToInteger(line);

		string ret = Solution().countAndSay(n);

		string out = (ret);
		cout << out << endl;
	}
	return 0;
}