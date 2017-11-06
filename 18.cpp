#include "universal.h"

//����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
//���磬����������¾��� 
//1 2 3 4 
//5 6 7 8 
//9 10 11 12 
//13 14 15 16 
//�����δ�ӡ������
//1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector <int> result;
		if (!matrix.size()||!matrix[0].size())
			return result;
		int up = -1, down = matrix.size(), left = -1, right = matrix[0].size();
		int line = 0, col = -1;
		while (true)
		{
			++col;
			if (col >= right)
				break;
			for (; col < right; ++col)
				result.push_back(matrix[line][col]);
			col--;
			up++;

			++line;
			if (line >= down)
				break;
			for (; line < down; ++line)
				result.push_back(matrix[line][col]);
			line--;
			right--;

			--col;
			if (col <= left)
				break;
			for (; col > left; --col)
				result.push_back(matrix[line][col]);
			col++;
			down--;

			--line;
			if (line <= up)
				break;
			for (; line > up;--line)
				result.push_back(matrix[line][col]);
			line++;
			left++;
		}
		return result;
	}
};