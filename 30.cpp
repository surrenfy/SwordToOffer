#include "universal.h"

//求出[0,n]中1出现的次数。

//当计算右数第  i  位包含的 X 的个数时：
//1.取第  i  位左边（高位）的数字，乘以 10^(i−1) ，得到基础值 a 。
//2.取第  i  位数字，计算修正值：
//	如果大于 X，则结果为  a + 10 i−1 。
//	如果小于 X，则结果为  a 。
//	如果等于 X，则取第  i  位右边（低位）数字，设为  b ，最后结果为  a + b + 1 。
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n <= 0)
			return 0;
		int x = 1;
		int dxp[10];
		dxp[0] = 1;
		for (int i = 1; i < 10; i++)
			dxp[i] = dxp[i - 1] * 10;
		int high = n, low, curr, tmp, i = 1, total = 0;
		while (high != 0) {
			high = n / dxp[i];// 获取第i位的高位
			tmp = n % dxp[i];
			curr = tmp / dxp[i - 1];// 获取第i位
			low = tmp % dxp[i - 1];// 获取第i位的低位
			if (curr == x) {
				total += high*dxp[i - 1] + low + 1;
			}
			else if (curr<x) {
				total += high*dxp[i - 1];
			}
			else {
				total += (high + 1)*dxp[i - 1];
			}
			i++;
		}
		return total;
	}
};