#include "universal.h"

//����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣

//��סstable_partition�������ĺ���

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		stable_partition(array.begin(), array.end(), isOdd);
	}
	static bool isOdd(int i) { return ((i & 1) == 1); }
};