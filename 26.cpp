#include "universal.h"

//输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

//字典序法：在当前序列中，从尾端往前寻找两个相邻元素，前一个记为*i，后一个记为*ii，并且满足*i < *ii。
//然后再从尾端寻找另一个元素*j，如果满足*i < *j，即将第i个元素与第j个元素对调，并将第ii个元素之后（包括ii）的所有元素颠倒排序，即求出下一个序列了。
class Solution {
public:
	vector<string> Permutation(string str) {
		size_t size = str.length();
		vector<string> res;
		if (!size)
			return res;
		char* s = new char[size + 1];
		strcpy(s, str.c_str());
		sort(s, s + size);
		do {
			res.push_back(string(s));
		} while (next_permutation(s, s + size));
		return res;
	}
};