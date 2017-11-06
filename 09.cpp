#include "universal.h"

//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������

//����ÿ��̨�� ���в���ȥ��û��������� ����2^(n-1)
//�Լ�д�Ŀ�����
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