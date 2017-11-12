#include "universal.h"

//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
//（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）


struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (!pHead)
			return NULL;
		//turn A->B.. to  A->A'->B->B'..
		RandomListNode* p = pHead, *q ,*r;
		while (p)
		{
			q = new RandomListNode(p->label);
			q->next = p->next;
			p->next = q;
			p = q->next;
		}
		//clone random
		p = pHead;
		while (p)
		{
			p->next->random = p->random == NULL ? NULL : p->random->next;
			p = p->next->next;
		}
		//take apart the list
		RandomListNode * res = pHead->next;
		p = pHead;
		p->next = res->next;
		p = p->next;
		q = res;
		while (p)
		{
			q->next = p->next;
			q = q->next;
			p->next = q->next;
			p = p->next;
		}
		return res;
	}
};