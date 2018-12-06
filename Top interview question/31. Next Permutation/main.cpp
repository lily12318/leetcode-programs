#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:

 	void nextPermutation(vector<int>& nums) {
		int i = nums.size() - 2;
		int k = nums.size() - 1;
		
		for (; i >= 0; --i)
		{
			if (nums[i] < nums[i+1])
			{
				for (; k > i; --k)
				{
					if (nums[k] > nums[i])
					{
						break;
					}
				}
				swap(nums[i], nums[k]);
				break;
			}
		}
		sort(nums.begin() + (i + 1), nums.end());
	}

	//My Answer
	/*
	void nextPermutation(vector<int>& nums) {
		int LargerNumIndex = -1;
		bool IsFindLargerNum = findSmallerNumIndex(nums, LargerNumIndex);
		if (IsFindLargerNum)
		{
			int SmallestNumIndex = findSmallestNumIndex(nums, LargerNumIndex);
			exchangeNums(nums, LargerNumIndex, SmallestNumIndex);
		}
		sortInAscendingOrder(nums, LargerNumIndex);
	}

	//Find a number that smaller than next number
	bool findSmallerNumIndex(const vector<int>& vNums, int& voIndex)
	{
		for (size_t i = vNums.size() - 1; i > 0; --i)
		{
			if (vNums[i - 1] < vNums[i])
			{
				voIndex = i-1;
				return true;
			}
		}
		return false;
	}

	//find Smallest number but larger than num[vStartIndex]
	int findSmallestNumIndex(const vector<int>& vNums, int vStartIndex)
	{
		int ElementIndex = -1;
		for (size_t i = vNums.size()-1; i > vStartIndex; --i)
		{
			if (vNums[i] > vNums[vStartIndex])
			{
				ElementIndex = i;
				break;
			}
		}
		return ElementIndex;
	}

	void exchangeNums(vector<int>& vNums, int vFirstIndex, int vSecondIndex)
	{
		int Temp = vNums[vFirstIndex];
		vNums[vFirstIndex] = vNums[vSecondIndex];
		vNums[vSecondIndex] = Temp;
	}

	void sortInAscendingOrder(vector<int>& vNums, int vStartIndex)
	{
		if (vStartIndex == -1)
			sort(vNums.begin(), vNums.end());
		else
			sort(vNums.begin()+vStartIndex+1, vNums.end());
	}*/
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

		Solution().nextPermutation(nums);

		string out = integerVectorToString(nums);
		cout << out << endl;
	}
	return 0;
}