#include "universal.h"
#include <iostream>
//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
//����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء� ��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� 
//NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		size_t size = rotateArray.size();
		if (size == 0)
			return 0;
		else if (rotateArray[0] < rotateArray[size - 1]) // ���ﲻ��д�� <= {1,0,1}
			return rotateArray[0];
		else return minNumberInRotateArray(rotateArray, 0, size - 1);
	}
	int minNumberInRotateArray(vector<int>& rotateArray, size_t begin, size_t end) {
		if (end - begin < 1)
			return 0;
		if (rotateArray[begin] > rotateArray[begin + 1])
			return rotateArray[begin + 1];
		if (rotateArray[end - 1] > rotateArray[end])
			return rotateArray[end];
		long long diff = rotateArray[begin] - rotateArray[(begin + end) / 2];
		if (diff < 0)
			return minNumberInRotateArray(rotateArray, (begin + end) / 2, end);
		else if (diff < 0)
			return minNumberInRotateArray(rotateArray, begin, (begin + end) / 2);
		else return minNumberInRotateArray(rotateArray, begin + 1, end);
	}
};
