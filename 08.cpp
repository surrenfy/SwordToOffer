#include "universal.h"

//һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������

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