#include "universal.h"

//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (!sequence.size())
			return false;
		return VerifySquenceOfBST(sequence, 0, sequence.size());
	}
	bool VerifySquenceOfBST(vector<int>& sequence,size_t begin,size_t end) {
		if (begin + 3 > end)//like begin=0,end=2;can't use minus,because size_t must be non-negative
			return true;
		//it means end>=2
		int center = sequence[end - 1];
		int i,j;
		for (i = begin; i < end&&sequence[i] < center; i++)
			;
		j = i;
		for (; i < end&&sequence[i] > center; i++)
			;
		if (i == end - 1)
			return VerifySquenceOfBST(sequence, begin, j) && VerifySquenceOfBST(sequence, j, end - 1);
		else return false;
	}
};