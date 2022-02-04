// OJ: https://leetcode.com/problems/next-greater-node-in-linked-list/
// Author: Kiranpal Singh
class Solution
{
public:
    ListNode *reverseLL(ListNode *head)
    {
        ListNode dummy(0);
        while (head)
        {
            auto node = head;
            head = head->next;
            node->next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> answer;
        stack<int> s;
        head = reverseLL(head);
        while (head)
        {
            auto node = head;
            head = head->next;
            int n = node->val;
            while (s.size() && s.top() <= n)
            {
                s.pop();
            }
            answer.push_back(s.size() ? s.top() : 0);
            s.push(n);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};