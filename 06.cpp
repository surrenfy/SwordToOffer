#include "universal.h"
#include <iostream>
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		size_t size = rotateArray.size();
		if (size == 0)
			return 0;
		else if (rotateArray[0] < rotateArray[size - 1]) // 这里不能写成 <= {1,0,1}
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
