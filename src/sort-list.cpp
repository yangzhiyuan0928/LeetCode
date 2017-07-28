// sort-list.cpp : 定义控制台应用程序的入口点。
// Sort a linked list in O(n log n) time using constant space complexity.
// 排序算法中时间复杂度为O(n log n)的有：归并排序、快速排序、堆排序
// 空间复杂度为常数的排序算法有(当元素是数组时)：插入、冒泡、选择、堆排序
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;


struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL) {}
};

ListNode* CreateList(int len)  //创建长度为len的单链表
{
	ListNode* header = new ListNode(0);
	ListNode* head = header;
	srand((unsigned int)time(NULL));
	for(int i=0;i<len;i++)
	{
		ListNode* node = new ListNode(0);
		node->val = rand()%len - len/2;
		cout << node->val << " ";
		head->next = node;
		head = head->next;
	}
	return header->next;
}
//解法一：归并排序算法
class Solution 
{
public:
	ListNode* findMiddle(ListNode* head)  //注意：head不是指头结点，而是指单链表的第一个节点，其数据项有效
	{
		ListNode *slow = head, *fast = head;
		while(fast!=NULL && fast->next!=NULL && fast->next->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)  //归并两个有序链表
	{
		if(l1 == NULL)
			return l2;
		if(l2 == NULL)
			return l1;
		ListNode dummy = ListNode(0);
		ListNode* head = &dummy;
		while(l1 != NULL && l2 != NULL)
		{
			if(l1->val < l2->val)
			{
				head->next = l1;
				l1 = l1->next;
			}
			else
			{
				head->next = l2;
				l2 = l2->next;
			}
			head = head->next;
		}
		if(l1 != NULL)
			head->next = l1;
		if(l2 != NULL)
			head->next = l2;

		return dummy.next;
	}

	ListNode* sortList(ListNode* head) 
	{
		if(head == NULL || head ->next == NULL)
			return head;
		ListNode* middle = findMiddle(head);
		ListNode* right = sortList(middle->next);
		middle -> next = NULL;
		ListNode* left = sortList(head);
		return mergeTwoLists(left, right);	
	}
};

#define LEN 10
int main()
{
	Solution so;
	ListNode* header = new ListNode(0);  //链表头结点，数据域无效，不参与排序
	ListNode* head = header;
	srand((unsigned int)time(NULL));
	for(int i=0;i<LEN;i++)
	{
		ListNode* node = new ListNode(0);
		node->val = rand()%LEN - LEN/2;
		cout << node->val << " ";
		head->next = node;
		head = head->next;
	}
	//ListNode *head = CreateList(5);  //包含head,共5个节点
	ListNode *node = so.sortList(header->next);
	cout << endl;
	while(node!=NULL)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;

	//单链表删除
	return 0;
}


#include <string>
#include <iostream>
using namespace std;

#include <vector>
class Solution {  
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> ret;
		for(int i=0;i<s.size();i++)
		{
			int j=i+1;
			while(s[j] != s[i] && j<s.size())
			{
				j++;
			}
			ret.push_back(j-i);
		}
		int mlen = ret[0];
		for(int k=1;k<ret.size();k++)
		{
			if(mlen < ret[k])
				mlen = ret[k];
		}
		return mlen;
	}
};

int main()
{
	string str;
	getline(cin,str);
	Solution su;
	cout << su.lengthOfLongestSubstring(str) << endl;
	return 0;
}