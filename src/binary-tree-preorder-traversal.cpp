#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/***
 * iterator version:
 **/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root)
			return res;
		stack<TreeNode*> s;
		if (root)
			s.push(root);
		while (!s.empty()) {
			root = s.top();
			s.pop();
			res.push_back(root->val);
			if (root->right)
				s.push(root->right);
			if (root->left)
				s.push(root->left);
		}
		return res;
	}
};

/***
 * recursion version:
 **/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root)
			return res;
		travprev(root, res);
		return res;
	}
private:
	void travprev(TreeNode *root, vector<int> &vec) {
		if (!root)
			return;
		vec.push_back(root->val);
		travprev(root->left, vec);
		travprev(root->right, vec);
	}
};

