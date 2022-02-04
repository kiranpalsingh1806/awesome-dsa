// OJ: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
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
    int ans = 0;
    int dfs(TreeNode *root, int maxVal)
    {
        if (root->val >= maxVal)
        {
            ans++;
        }
        maxVal = max(maxVal, root->val);
        if (root->left)
        {
            dfs(root->left, maxVal);
        }
        if (root->right)
        {
            dfs(root->right, maxVal);
        }
        return ans;
    }
    int goodNodes(TreeNode *root)
    {
        return dfs(root, INT_MIN);
    }
};