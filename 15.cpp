#include "universal.h"

//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

//简单的归并排序，不需要自己申请节点，用已有的就行
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
}; 

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (!pHead1)
			return pHead2;
		if (!pHead2)
			return pHead1;
		ListNode *p = pHead1, *q = pHead2;
		ListNode *head, *current;
		if (p->val <= q->val)
		{
			head = pHead1;
			current = pHead1;
			p = p->next;
		}
		else {
			head = pHead2;
			current = pHead2;
			q = q->next;
		}
		while (p && q)
		{
			if (p->val <= q->val)
			{
				current->next = p;
				current = p;
				p = p->next;
			}
			else {
				current->next = q;
				current = q;
				q = q->next;
			}
		}
		if (p)
			current->next = p;
		else current->next = q;
		return head;
	}
};