class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int sum=0;
        for(int x: nums) sum+=x;
        
        int ans1 = INT_MIN;
        int cur = INT_MIN;
        
        for(int x: nums){
            cur = x + max(cur,0);
            ans1 = max(ans1, cur);
        }
        
        int ans2 = INT_MAX;
        cur = INT_MAX;
        
        for(int i = 1; i < nums.size(); ++i){
            cur = nums[i] + min(cur,0);
            ans2 = min(ans2, cur);
        }
        if(ans2 == INT_MAX) ans2 = INT_MIN;
        else ans2 = sum-ans2;
        
        
        int ans3 = INT_MAX;
        cur = INT_MAX;
        
        for(int i = 0; i < nums.size()-1; ++i){
            cur = nums[i] + min(cur,0);
            ans3 = min(ans3, cur);
        }
        
        if(ans3 = INT_MAX) ans3 = INT_MIN;
        
        return max(ans1, max(ans2,ans3));
    }
};