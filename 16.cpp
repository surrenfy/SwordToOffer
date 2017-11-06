#include "universal.h"

//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）


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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (!pRoot1 || !pRoot2)
			return false;
		return (IsSametree(pRoot1,pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2));
	}
	bool IsSametree(TreeNode* p, TreeNode* q)
	{
		if (!q)
			return true; //注意此处
		if (!p)
			return false;
		return (p->val == q->val && IsSametree(p->left, q->left) && IsSametree(p->right, q->right));
	}
};
