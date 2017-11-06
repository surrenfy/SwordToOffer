#include "universal.h"

//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��


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
			return true; //ע��˴�
		if (!p)
			return false;
		return (p->val == q->val && IsSametree(p->left, q->left) && IsSametree(p->right, q->right));
	}
};
