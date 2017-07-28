#include <cstdio>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {  //single-linked list sorted
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *dummy = new ListNode(-1);
		while (head != NULL)
		{
			ListNode *temp = head->next;  //backup
			ListNode *curnode = searchinsertAfter(dummy, head->val);  //sorted list curent node.			
			head->next = curnode->next;  //curent->next->val > head->val
			curnode->next = head; //insert head
			head = temp;
		}
		ListNode *res = dummy->next;
		delete(dummy);
		return res;
	}
private:
	ListNode *searchinsertAfter(ListNode *head, int val) {  //head->val is nonsense.
		if (head == NULL || head->next == NULL) 
			return head;
		ListNode *cur = head;
		while (cur->next != NULL && cur->next->val <= val)  //"<=" for stable.
		{
			cur = cur->next;
		}
		return cur;
	}
};