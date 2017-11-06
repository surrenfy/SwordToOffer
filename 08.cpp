#include "universal.h"

//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

// f(1)=1; f(2)=2; f(n)=f(n-1)+f(n-2) n>2;

class Solution {
public:
	int jumpFloor(int number) {
		int f = 1, g = 0;
		while (number--)
		{
			f = f + g;
			g = f - g;
		}
		return f;
	}
};