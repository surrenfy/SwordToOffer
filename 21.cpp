#include "universal.h"

//从上往下打印出二叉树的每个节点，同层节点从左至右打印。


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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector <int> res;
		if (!root)
			return res;
		queue <TreeNode*> q;
		TreeNode *p;
		q.push(root);
		while (!q.empty())
		{
			p = q.front();
			q.pop();
			res.push_back(p->val);
			if (p->left)
				q.push(p->left);
			if (p->right)
				q.push(p->right);
		}
		return res;
	}
};