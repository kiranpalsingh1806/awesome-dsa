// OJ: https://leetcode.com/problems/reverse-linked-list-ii/
// Author: Kiranpal Singh
}
;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode h, *p = &h;
        h.next = head;
        for (int i = 1; i < left && p; i++)
        {
            p = p->next;
        }
        ListNode *q = p->next;
        auto tail = q;
        for (int i = left; i <= right && q; i++)
        {
            auto node = q;
            q = q->next;
            node->next = p->next;
            p->next = node;
        }
        tail->next = q;
        return h.next;
    }
};