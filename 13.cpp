#include "universal.h"

//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

//记住stable_partition这个神奇的函数

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		stable_partition(array.begin(), array.end(), isOdd);
	}
	static bool isOdd(int i) { return ((i & 1) == 1); }
};