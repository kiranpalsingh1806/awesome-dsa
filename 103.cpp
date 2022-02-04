// OJ: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Author: Kiranpal Singh
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        bool l2r = true;
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> answer;
        while (q.size())
        {
            int cnt = q.size();
            vector<int> level;
            while (cnt--)
            {
                TreeNode *temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            if (!l2r)
            {
                reverse(level.begin(), level.end());
            }
            answer.push_back(level);
            l2r = !l2r;
        }
        return answer;
    }
};