#include "universal.h"

//���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����

//����쳲��������У��͵�8��ûɶ����
class Solution {
public:
	int rectCover(int number) {
		if (number == 0)
			return 0;
		int f = 1, g = 0;
		while (number--)
		{
			f = f + g;
			g = f - g;
		}
		return f;
	}
};