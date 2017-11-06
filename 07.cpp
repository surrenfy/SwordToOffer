#include "universal.h"

//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。

class Solution {
public:
	int Fibonacci(int n) {
		int f = 0, g = 1;
		while (n--)
		{
			f = f + g;
			g = f - g;
		}
		return f;
	}
};