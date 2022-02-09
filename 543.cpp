// OJ: https://leetcode.com/problems/diameter-of-binary-tree/
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
    int answer = 0;
    int dfs(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        answer = max(answer, left + right);
        return (1 + max(left, right));
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return answer;
    }
};