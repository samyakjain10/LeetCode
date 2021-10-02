class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        vector<int> dp(n+1);
        dp[0]=INT_MIN;
        for(int i=1;i<=n;i++) dp[i]=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int pos=upper_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            if(dp[pos-1]<nums[i])
            {
             dp[pos]=nums[i];
            }
        }
        int ans=1;
       for(int i=1;i<=n;i++)
       {
           if(dp[i]!=INT_MAX)
              ans= i;
       }
        return ans;
    }
};