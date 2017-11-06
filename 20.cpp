#include "universal.h"

//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
//��������1,2,3,4,5��ĳջ��ѹ��˳������4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		size_t size = pushV.size();
		if (size != popV.size())
			return false;
		stack <int> s;
		size_t j = 0;
		for (size_t i = 0; i < size; i++)
		{
			s.push(pushV[i]);
			while (!s.empty() && s.top() == popV[j])
			{
				s.pop();
				j++;
			}
		}
		return s.empty();
	}
};