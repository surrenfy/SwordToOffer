#include "universal.h"

//输入一个链表，从尾到头打印链表每个节点的值。

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
  public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> temp;
        ListNode *p = head;
        while (p)
        {
            temp.push_back(p->val);
            p = p->next;
        }
        return vector<int>(temp.rbegin(), temp.rend());
    }
};