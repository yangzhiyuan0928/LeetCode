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
* recursion version:
**/
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
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
		travprev(root->left, vec);
		travprev(root->right, vec);
		vec.push_back(root->val);
	}
};