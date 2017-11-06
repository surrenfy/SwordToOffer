#include "universal.h"

//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

//对于每个台阶 都有踩上去和没踩两种情况 答案是2^(n-1)
//自己写的快速幂
class Solution {
public:
	int jumpFloorII(int number) {
		return pow_2(number-1);
	}
	int pow_2(int factor)
	{
		int res = 1;
		int base = 2;
		while (factor)
		{
			if (factor & 0x1)
				res *= base;
			factor >>= 1;
			base *= base;
		}
		return res;
	}
};