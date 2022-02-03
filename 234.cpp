// OJ: https://leetcode.com/problems/palindrome-linked-list/
// Author: Kiranpal Singh
class Solution {
            dummy.next = node;
        }
        return dummy.next;
    }
    bool isPalindrome(ListNode* head) {
        if(!head) {
            return true;
        }
        int length = (getLength(head) + 1) / 2;
        ListNode* p = head;
        while(--length) {
            p = p->next;
        }
        ListNode* q = p->next;
        p->next = NULL;
        q = reverse(q);
        while(head && q) {
            if(head->val != q->val) {
                return false;
            }
            head = head->next;
            q = q->next;
        }
        return true;
    }
};