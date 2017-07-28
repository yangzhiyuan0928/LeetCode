#include <cstdio>
using namespace std;

// Definition for single-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#include <vector>
class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL)
			return;
		vector<ListNode*> vec;
		for (ListNode *node = head; node != NULL; node = node->next)
		{
			vec.push_back(node);
		}
		int ls = vec.size();
		int st = 0, en = ls - 1;
		while (st < en)
		{
			vec[st]->next = vec[en];
			vec[en]->next = vec[st + 1];
			st++;
			en--;
		}
		vec[st]->next = NULL;
	}
};