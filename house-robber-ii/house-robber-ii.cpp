class Solution
{
public:
    unordered_map<string, int> um;

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int v1 = nums[0] + solve(nums, 1, true, true);
        int v2 = solve(nums, 1, false, false);

        return max(v1, v2);
    }

    int solve(vector<int> &nums, int n, bool prevrob, bool firstrob)
    {

        string key = to_string(n) + '_' + to_string(prevrob) + '_' + to_string(firstrob);

        if (n == nums.size())
            return 0;

        if (n == nums.size() - 1 && firstrob)
            return 0;

        if (um.find(key) != um.end())
            return um[key];

        if (prevrob)
        {
            return um[key] = solve(nums, n + 1, false, firstrob);
        }
        else
            return um[key] = max(nums[n] + solve(nums, n + 1, true, firstrob), solve(nums, n + 1, false, firstrob));
    }
};