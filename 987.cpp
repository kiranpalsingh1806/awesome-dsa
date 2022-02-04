// OJ: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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
    vector<vector<int>> answer;
    map<int, map<int, multiset<int>>> m;
    void dfs(TreeNode *root, int x, int y)
    {
        if (!root)
        {
            return;
        }
        m[x][y].insert(root->val);
        dfs(root->left, x - 1, y + 1);
        dfs(root->right, x + 1, y + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        dfs(root, 0, 0);
        for (auto &[mm, mm1] : m)
        {
            answer.emplace_back();
            for (auto &[mm2, vals] : mm1)
            {
                for (int n : vals)
                {
                    answer.back().push_back(n);
                }
            }
        }
        return answer;
    }
};