class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> tmp(k);
        int N = nums.size();

        k %= N;

        for (int i = 0; i < k; i++)
        {
            tmp[i] = nums[N - k + i];
        }

        for (int i = N - 1; i >= k; i--)
        {
            nums[i] = nums[i - k];
        }

        for (int i = 0; i < k; i++)
        {
            nums[i] = tmp[i];
        }
    }
};