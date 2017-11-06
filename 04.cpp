#include "universal.h"

//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

 //Definition for binary tree
 struct TreeNode
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution
 {
   public:
     TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
     {
         return reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
     }
     TreeNode *reConstructBinaryTree(vector<int>& pre, unsigned int p_begin,unsigned int p_end,vector<int>& vin,unsigned int v_begin,unsigned int v_end)
     {
        if (p_begin > p_end)
            return NULL;
        if (p_begin == p_end)
			return new TreeNode(pre[p_begin]);

		int center = pre[p_begin];
		TreeNode * root = new TreeNode(center);
		unsigned int pos = v_begin;
		while (vin[pos] != center)
			pos++;
		if (pos == v_begin)
			root->left = NULL;
		else root->left = reConstructBinaryTree(pre, p_begin + 1, p_begin + pos - v_begin, vin, v_begin, pos - 1);
		if (pos == v_end)
			root->right = NULL;
		else root->right = reConstructBinaryTree(pre, p_begin + pos - v_begin + 1, p_end, vin, pos + 1, v_end);
		return root;
     }
};
