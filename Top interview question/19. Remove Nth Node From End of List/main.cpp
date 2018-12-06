//此题目本身重点在给定一个List倒数的n，如何尽快的将倒数n体现为正序的n'

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


/*Two pass algorithm
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int Count_size = 0;
		for (ListNode* pTemp = head; pTemp != NULL; pTemp = pTemp->next)
			Count_size++;
		int Target_index = Count_size - n;
		int Index = 0;
		if (Target_index == 0)
			return head->next;
		ListNode* pTemp = head->next;
		ListNode* curNode = head;
		for (; pTemp != NULL; pTemp = pTemp->next, Index++)
		{
			if (Index == Target_index - 1)
			{
				curNode->next = pTemp->next;
				break;
			}
			curNode->next = pTemp;
			curNode = curNode->next;
		}
		return head;
	}
};*/

//one pass algorithm
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* pDummy = new ListNode(0);
		pDummy->next = head;
		ListNode* pFirst = pDummy;
		ListNode* pSecond = pDummy;
		for (size_t i = 0; i < n + 1; i++)
			pFirst = pFirst->next;
		while (pFirst != NULL)
		{
			pFirst = pFirst->next;
			pSecond = pSecond->next;
		}
		pSecond->next = pSecond->next->next;
		return pDummy->next;
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

ListNode* stringToListNode(string input) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

int stringToInteger(string input) {
	return stoi(input);
}

string listNodeToString(ListNode* node) {
	if (node == nullptr) {
		return "[]";
	}

	string result;
	while (node) {
		result += to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		ListNode* head = stringToListNode(line);
		getline(cin, line);
		int n = stringToInteger(line);

		ListNode* ret = Solution().removeNthFromEnd(head, n);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}