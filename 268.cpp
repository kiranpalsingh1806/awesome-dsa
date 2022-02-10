// OJ: https://leetcode.com/problems/missing-number/
// Author: Kiranpal Singh
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans ^= (nums[i] ^ (i + 1));
        }
        return ans;
    }
};