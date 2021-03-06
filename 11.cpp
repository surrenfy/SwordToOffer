#include "universal.h"

//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

// n = n & (n-1) 会把n最右面的1变为0
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		while (n) {
			count ++;
			n = n & (n - 1);
		}
		return count;
	}
};