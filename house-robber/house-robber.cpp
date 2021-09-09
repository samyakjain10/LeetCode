class Solution {
public:
    
    int helper(vector<int>& nums, int n, vector<int>& ans){
        
        if(n<0){
            return 0;
        }
        
        if(ans[n]!=INT_MAX) return ans[n];
        
        ans[n] = max(nums[n]+helper(nums,n-2,ans), helper(nums,n-1,ans));
            
        return ans[n];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n+1,INT_MIN);
        
        if(n<1) return 0;
        
        ans[0] = 0;
        ans[1] = nums[0];
        
        for(int i=2; i<=n; i++){
            ans[i] = max(nums[i-1]+ans[i-2], ans[i-1]);
        }
        
        return ans[n];
    }
};