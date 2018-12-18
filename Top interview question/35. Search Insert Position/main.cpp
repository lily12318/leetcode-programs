#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0) return 0;
		int Low = 0, High = nums.size()-1;
		int Mid;
		while (Low < High)
		{
			Mid = (Low + High) / 2;
			if (nums[Mid] >= target) High = Mid;
			else Low = Mid + 1;
		}
		if (nums[Low] >= target) return Low;
		else return Low + 1;
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

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);
		getline(cin, line);
		int target = stringToInteger(line);

		int ret = Solution().searchInsert(nums, target);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}