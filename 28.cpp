#include "universal.h"

//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		if (!k || k > input.size())
			return res;
		nth_element(input.begin(), input.begin() + k - 1, input.end());
		int partition = input[k - 1];

		size_t size = input.size();
		for (size_t i = 0; i < size; i++)
			if (input[i] <= partition)
				res.push_back(input[i]);
		sort(res.begin(), res.end());
		res.resize(k);
		return res;
	}
};