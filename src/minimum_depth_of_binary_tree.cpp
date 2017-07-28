// minimum_depth_of_binary_tree.cpp : 定义控制台应用程序的入口点。
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
	int run(TreeNode *root)  //递归版本
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
	int run(TreeNode *root)  //迭代版本: 二叉树的层次遍历，遇到叶节点就返回
	{
		if(root == NULL)
			return 0;
		queue<TreeNode*> q;
		TreeNode *tail = root;  //每层最后一个节点
		int depth = 0;
		while(!q.empty())
		{
			TreeNode *node = q.front(); //取队列头节点
			q.pop();
			if(node->left != NULL)
				q.push(node->left);
			if(node->right != NULL)
				q.push(node->right);
			if(node == tail)  //从队列中取出的正好是某层的尾节点：更新尾节点
			{
				depth++;  //访问完一层
				if(node->right != NULL)
					tail = node->right;
				else if(node->left != NULL)
					tail = node->left;
				else
					break;  //层尾节点为叶节点
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