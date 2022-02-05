// OJ: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author: Kiranpal Singh
q.push(root);
while (q.size())
{
    int cnt = q.size();
    Node *prev = nullptr;
    while (cnt--)
    {
        auto node = q.front();
        q.pop();
        // Pointer Update
        if (prev)
        {
            prev->next = node;
        }
        prev = node;
        if (node->left)
        {
            q.push(node->left);
        }
        if (node->right)
        {
            q.push(node->right);
        }
    }
}
return root;
}
Node *connect(Node *root)
{
    if (!root)
    {
        return NULL;
    }
    return dfs(root);
}
}
;