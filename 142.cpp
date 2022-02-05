// OJ: https://leetcode.com/problems/linked-list-cycle-ii/
// Author: Kiranpal Singh
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode *p = head, *q = head;
        while (q && q->next)
        {
            p = p->next;
            q = q->next->next;
            if (p == q)
            {
                break;
            }
        }
        if (!q || !q->next)
        {
            return NULL;
        }
        for (q = head; p != q; p = p->next, q = q->next)
            ;
        return q;
    }
};