#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int Left = 0;
		int Right = height.size() - 1;
		int MaxArea = calculateArea(0, height.size() - 1, height[Left], height[Right]);
		while (Left < Right)
		{
			if (height[Left] < height[Right])
				Left++;
			else
				Right--;
			int CurArea = calculateArea(Left, Right, height[Left], height[Right]);
			MaxArea = CurArea > MaxArea ? CurArea : MaxArea;
		}
		return MaxArea;
	}

	int calculateArea(int x1, int x2, int y1, int y2)
	{
		int Min_y = y1 < y2 ? y1 : y2;
		return (abs(x2 - x1) * Min_y);
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> height = stringToIntegerVector(line);

		int ret = Solution().maxArea(height);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}