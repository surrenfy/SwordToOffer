#include "universal.h"

//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������

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