#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		const int R = 10;
		ListNode *p1 = l1, *p2 = l2, *p3 = NULL;
		ListNode *rlist = NULL;
		ListNode *p = NULL;
		ListNode *ptr = NULL;
		while(p1 != NULL && p2 != NULL)
		{
			p3 = new ListNode(p1->val + p2->val);
			p1 = p1->next;
			p2 = p2->next;
			if(rlist == NULL)
			{
				rlist = p = p3;
			}
			else
			{
				p->next = p3;
				p = p3;
			}
		}
		while(p1 != NULL)
		{
			p3 = new ListNode(p1->val);
			p1 = p1->next;
			p->next = p3;
			p = p3;
		}
		while(p2 != NULL)
		{
			p3 = new ListNode(p2->val);
			p2 = p2->next;
			p->next = p3;
			p = p3;		
		}
		int r = 0;
		for(ptr=rlist; ptr!=NULL; ptr=ptr->next)
		{
			ptr->val = r + ptr->val;
			r = ptr->val/R;
			ptr->val = ptr->val % R;
		}	
		if(r>0)
		{
		    p3 = new ListNode(r);
		    p->next = p3;
		    p = p3;
		}
		return rlist;
	}
};
