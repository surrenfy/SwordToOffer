#include "universal.h"

//求连续子向量和的最大值
//例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。

//动态规划 记录以某个节点为结尾的子向量的和的最大值
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (!array.size())
			return 0;
		size_t size = array.size();
		vector<int> sum;
		sum.push_back(array[0]);
		int maxSum = array[0];
		for (size_t i = 1; i < size; i++)
		{
			if (sum[i - 1] <= 0)
				sum.push_back(array[i]);
			else sum.push_back(array[i] + sum[i - 1]);
			if (sum.back() > maxSum)
				maxSum = sum.back();
		}
		return maxSum;
	}
};