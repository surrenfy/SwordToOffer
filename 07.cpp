#include "universal.h"

//��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�

class Solution {
public:
	int Fibonacci(int n) {
		int f = 0, g = 1;
		while (n--)
		{
			f = f + g;
			g = f - g;
		}
		return f;
	}
};