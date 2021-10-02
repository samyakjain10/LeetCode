class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int x = bs(nums, target);
        int y = bs(nums, target + 1) - 1;
        if (x < nums.size() && nums[x] == target)
            return {x, y};
        else
            return {-1, -1};
    }

    int bs(vector<int> nums, int target)
    {
        int lo = 0, hi = nums.size() - 1;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] < target)
            {
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return lo;
    }
};