//此题实际上是按大小顺序将两个链表的元素合并

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
/*//解法1：
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* pDummy = new ListNode(0);
		ListNode* pCurNode = pDummy;
		while (l2 != NULL || l1 != NULL)
		{
			if (l1 && l2)
			{
				if (l1->val > l2->val)
				{
					pCurNode->next = l2;
					l2 = l2->next;
				}
				else
				{
					pCurNode->next = l1;
					l1 = l1->next;
				}
			}
			else
			{
				pCurNode->next = l1 == NULL ? l2 : l1;
				break;
			}	
			pCurNode = pCurNode->next;
		}
		return pDummy->next;
	}*/

	//解法2：
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)	return l2;
		if (l2 == NULL)	return l1;
		ListNode* pHead = l1->val <= l2->val ? l1 : l2;
		ListNode* pNoHead = l1->val <= l2->val ? l2 : l1;
		pHead->next = mergeTwoLists(pHead->next, pNoHead);
		return pHead;
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
		ListNode* l1 = stringToListNode(line);
		getline(cin, line);
		ListNode* l2 = stringToListNode(line);

		ListNode* ret = Solution().mergeTwoLists(l1, l2);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}