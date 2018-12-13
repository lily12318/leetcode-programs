#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	//My answer
	/*
  	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
 		int Low = 0;
 		int High = nums.size() - 1;
 		int Split = searchSplit(nums, Low, High);
		if (Low <= Split && Split < High)
		{
			if (target >= nums[Low])	High = Split;
			else	Low = Split + 1;
		}
		int TargetIndex = binarySearch(nums, Low, High, target);
		return TargetIndex;
	}
	int searchSplit(vector<int>& vNums, int vLow, int vHigh)
	{
		int mid = -1;
		while (vNums[vLow] > vNums[vHigh])
		{
			mid = (vLow + vHigh) / 2;
			if (vNums[vLow] > vNums[mid])
				vHigh = mid;
			else
				vLow = mid+1;
		}
		return mid;
	}
	int binarySearch(vector<int>& vNums, int vLow, int vHigh, int vTarget)
	{
		if (vTarget < vNums[vLow] || vTarget > vNums[vHigh]) return -1;
		int mid = (vLow + vHigh) / 2;
 		if (vTarget < vNums[mid])	return binarySearch(vNums, vLow, mid, vTarget);
		else if (vTarget > vNums[mid])	return binarySearch(vNums, mid+1, vHigh, vTarget);
		else return mid;
	}*/

	//better answer
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)	return-1;
		int Low = 0, High = nums.size() - 1;
		while (Low < High)
		{
			int Mid = (Low + High) / 2;
			if (target == nums[Mid])	return Mid;
			//Left is sorted
			if (nums[Low] < nums[Mid])
			{
				if (target >= nums[Low] && target <= nums[Mid])
					High = Mid;
				else
					Low = Mid + 1;
			}
			//Right is sorted
			else
			{
				if (target >= nums[Mid+1] && target <= nums[High])
					Low = Mid + 1;
				else
					High = Mid;
			}
		}
		return (target == nums[Low]) ? Low : -1;
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

 		int ret = Solution().search(nums, target);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0; 
}