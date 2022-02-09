// OJ: https://leetcode.com/problems/house-robber/
// Author: Kiranpal Singh
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> theft(N + 1), noTheft(N + 1);
        for (int i = 0; i < N; i++)
        {
            theft[i + 1] = nums[i] + noTheft[i];
            noTheft[i + 1] = max(noTheft[i], theft[i]);
        }
        return max(theft[N], noTheft[N]);
    }
};