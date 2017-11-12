#include "universal.h"

//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
//核心思想：中序遍历

//非递归版 效率更高
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (!pRootOfTree)
			return NULL;
		TreeNode* pre = NULL, *p = pRootOfTree;
		stack <TreeNode*> s;
		while (p || !s.empty())
		{
			while (p) {
				s.push(p);
				p = p->left;
			}
			p = s.top();
			s.pop();
			if (pre)
				pre->right = p;
			p->left = pre;//注意
			pre = p;
			p = p->right;
		}
		while (pRootOfTree->left)
			pRootOfTree = pRootOfTree->left;
		return pRootOfTree;
	}
};

//递归版
/*
class Solution {
public:
TreeNode* Convert(TreeNode* pRootOfTree)
{
if (!pRootOfTree)
return NULL;
TreeNode* pre = NULL;
Convert(pRootOfTree, pre);
while (pRootOfTree->left)
pRootOfTree = pRootOfTree->left;
return pRootOfTree;
}
void Convert(TreeNode* pRootOfTree, TreeNode*& preNode)
{
if (pRootOfTree->left)
Convert(pRootOfTree->left, preNode);
if (preNode)
preNode->right = pRootOfTree;
pRootOfTree->left = preNode;//注意
preNode = pRootOfTree;
if (pRootOfTree->right)
Convert(pRootOfTree->right, preNode);
}
};*/
