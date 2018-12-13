#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> TargetIndex = { -1, -1 };
		if (nums.size() == 0) return TargetIndex;
		int Low = 0, High = nums.size() - 1;
		binary_find(nums, Low, High, target, TargetIndex);
		return TargetIndex;
	}

	void binary_find(vector<int>& vNums, int vLow, int vHigh, int vTarget, vector<int>& vioTargetIndex)
	{
		_ASSERTE(vioTargetIndex.size() == 2);
		if (vLow > vHigh) return;
		if (vLow == vHigh)
		{
			if (vNums[vLow] == vTarget)
			{
				if (vioTargetIndex[0] == -1 && vioTargetIndex[1] == -1)
				{
					vioTargetIndex[0] = vioTargetIndex[1] = vLow;
				}
				vioTargetIndex[0] = vioTargetIndex[0] <= vLow ? vioTargetIndex[0] : vLow;
				vioTargetIndex[1] = vioTargetIndex[1] >= vLow ? vioTargetIndex[1] : vLow;
			}
			return;
		}
		int Mid = (vLow + vHigh) / 2;
		if (vNums[Mid] == vTarget)
		{
			if (vioTargetIndex[0] == -1 && vioTargetIndex[1]  == -1)
			{
				vioTargetIndex[0] = vioTargetIndex[1] = Mid;
			}
			if (Mid < vioTargetIndex[0]) vioTargetIndex[0] = Mid;
			else if (Mid > vioTargetIndex[1]) vioTargetIndex[1] = Mid;
			binary_find(vNums, vLow, Mid - 1, vTarget, vioTargetIndex);
			binary_find(vNums, Mid + 1, vHigh, vTarget, vioTargetIndex);
		}
		else if (vNums[Mid] > vTarget) binary_find(vNums, vLow, Mid - 1, vTarget, vioTargetIndex);
		else binary_find(vNums, Mid + 1, vHigh, vTarget, vioTargetIndex);
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

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);
		getline(cin, line);
		int target = stringToInteger(line);

		vector<int> ret = Solution().searchRange(nums, target);

		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}