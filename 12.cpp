#include "universal.h"

//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

class Solution {
public:
	double Power(double base, int exponent) {
		return pow(base, exponent);
	}
};