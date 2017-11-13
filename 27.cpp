#include "universal.h"

//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		size_t size = numbers.size();
		if (!size)
			return 0;
		int result = numbers[0], times = 1;
		for (size_t i = 1; i < size; i++)
		{
			if (numbers[i] == result)
				times++;
			else if (times == 0)
			{
				times = 1;
				result = numbers[i];
			}
			else times--;
		}
		times = 0;
		for (size_t i = 0; i < size; i++)
			if (numbers[i] == result)
				times++;
		if (times * 2 > size)
			return result;
		else return 0;
	}
};