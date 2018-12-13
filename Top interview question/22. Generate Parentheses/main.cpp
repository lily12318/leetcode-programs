#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> Parenthesis;
		if (n == 0)	Parenthesis.push_back("");
		for (int c = 0; c < n; c++)
		{
			vector<string> Left = generateParenthesis(c);
			for (int i = 0; i < Left.size(); i++)
			{
				vector<string> Right = generateParenthesis(n - c - 1);
				for (int k = 0; k < Right.size(); k++)
				{
					Parenthesis.push_back("(" + Left[i] + ")" + Right[k]);
				}
			}
		}
		return Parenthesis;
	}
};*/

/*回溯法
n对括号成对出现，tmp代表string已经生成的字符串, Left代表剩余的"("个数, Right代表剩余的")"个数
生成满足题目要求的字符串, 则需满足：
1. 当Left>0时，可以加"("
2. 当Right>Left时，可以加")"
顺序执行上面两句，即可保证生成的字符串合法："("个数不会大于n；")"始终小于等于"("
*/
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		string Tmp = "";
		ParenthesisUntil(Tmp, n, n);
		return Result;
	}
	void ParenthesisUntil(string vTmp, int vLeft, int vRight)
	{
		if (vLeft == 0 && vRight == 0)
		{
			Result.push_back(vTmp);
			return;
		}
		if (vLeft > 0)
		{
			ParenthesisUntil(vTmp + "(", vLeft-1, vRight);
		}
		if (vRight > vLeft)
		{
			ParenthesisUntil(vTmp + ")", vLeft, vRight-1);
		}
	}

private:
	vector<string> Result;
};

int main()
{
	int n;
	cin >> n;
	vector<string> Parenthesis = Solution().generateParenthesis(n);
	for (size_t i = 0; i < Parenthesis.size(); i++)
	{
		cout << Parenthesis[i] << endl;
	}
	return 0;
}