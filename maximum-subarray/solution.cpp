class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            res = max(res, dp[i]);
        }
        return res;
    }
};