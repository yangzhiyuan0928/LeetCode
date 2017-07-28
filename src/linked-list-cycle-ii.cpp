#include <cstdio>
#include <string>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *fast, *slow;
		if (slow = crossListNode(head)) {
			fast = head;  //fast restart runing step by step from head.
			while (1)
			{
				if (fast == slow)
					return slow;
				fast = fast->next;
				slow = slow->next;  //slow run from the cross node.
			}
		}
		else
			return NULL;
	}

private:
	ListNode* crossListNode(ListNode *head) {  //return the cross node between fast and slow.
		if (head == NULL || head->next == NULL)
			return NULL;
		ListNode* fast = head, *slow = head; //fast slow
		while (1)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
				return slow;
			else if (fast == NULL || fast->next == NULL)  //use "slow->next == NULL" will be time out.
				return NULL;
		}
	}
};