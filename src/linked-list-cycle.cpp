#include <cstdio>
using namespace std;

// Definition for single-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return false;
		ListNode* fast = head, *slow = head; //fast slow
		while (1)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
				return true;
			else if (fast == NULL || fast->next == NULL)  //use "slow->next == NULL" will be time out.
				return false;
		}
	}
};