// minimum_depth_of_binary_tree.cpp : �������̨Ӧ�ó������ڵ㡣
//Given a binary tree, find its minimum depth.The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
};

class Solutions {
public:
	int run(TreeNode *root)  //�ݹ�汾
	{
		if(root == NULL)
			return 0;
		int l = run(root->left); 
		int r = run(root->right);
		if(l == 0 || r == 0)
			return 1+l+r;
		return 1 + min(l,r);
	}
};

#include <queue>
class Solutions {
public:
	int run(TreeNode *root)  //�����汾: �������Ĳ�α���������Ҷ�ڵ�ͷ���
	{
		if(root == NULL)
			return 0;
		queue<TreeNode*> q;
		TreeNode *tail = root;  //ÿ�����һ���ڵ�
		int depth = 0;
		while(!q.empty())
		{
			TreeNode *node = q.front(); //ȡ����ͷ�ڵ�
			q.pop();
			if(node->left != NULL)
				q.push(node->left);
			if(node->right != NULL)
				q.push(node->right);
			if(node == tail)  //�Ӷ�����ȡ����������ĳ���β�ڵ㣺����β�ڵ�
			{
				depth++;  //������һ��
				if(node->right != NULL)
					tail = node->right;
				else if(node->left != NULL)
					tail = node->left;
				else
					break;  //��β�ڵ�ΪҶ�ڵ�
			}
			if(node->left == NULL && node->right == NULL)
			{
				depth++;
				break;
			}
		}
		return depth;
	}
};