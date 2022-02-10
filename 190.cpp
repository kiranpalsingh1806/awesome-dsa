class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;

        for (int i = 0; i < 32; i++)
        {
            if (n & (1 << i))
            {                           // If nth bit is on
                ans |= (1 << (31 - i)); // Turn on 31 - nth bit in answer
            }
        }

        return ans;
    }
};