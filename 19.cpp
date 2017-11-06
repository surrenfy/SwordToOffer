#include "universal.h"

//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

class Solution {
public:
	void push(int value) {
		A.push(value);
		if (B.empty() || B.top() >= value)
			B.push(value);
	}
	void pop() {
		if (!A.empty())
		{
			if (A.top() == B.top())
			{
				A.pop();
				B.pop();
			}
			else 
				A.pop();
		}
	}
	int top() {
		return A.top();
	}
	int min() {
		return B.top();
	}
private:
	stack<int> A, B;
};