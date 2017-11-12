#include "universal.h"

//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

//重写了一遍，比原来要简单
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int> > res;
		if (!root)
			return res;
		vector <int> path;
		FindPath(root, expectNumber, path, res);
		return res;
	}
	void FindPath(TreeNode* root, int expectNumber, vector<int>& path, vector<vector<int>>& res) {
		path.push_back(root->val);
		expectNumber -= root->val;
		if (!root->left&&!root->right&&expectNumber == 0)
			res.push_back(path);
		if (root->left)
			FindPath(root->left, expectNumber, path, res);
		if (root->right)
			FindPath(root->right, expectNumber, path, res);
		path.pop_back();
	}
};