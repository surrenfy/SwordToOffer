#include "universal.h"

//����һ����������������е�����k����㡣

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		unsigned int i;
		ListNode*p=pListHead, *q=pListHead;
		for (i = 0; i < k && p; i++)
			p = p->next;
		if (i < k)
			return NULL;
		while (p) {
			p = p->next;
			q = q->next;
		}
		return q;
	}
};