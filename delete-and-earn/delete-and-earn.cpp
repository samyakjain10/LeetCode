class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int sums[10005];
        memset(sums,0,sizeof(sums));
        for(int i=0;i<nums.size();++i)
        {
            sums[nums[i]]+=nums[i];
        }
 
        int dp[10005];
        dp[1]=sums[1];
        dp[2]=max(sums[1],sums[2]);
 
        for(int i=3;i<10005;++i)
        {
            dp[i]=max(sums[i]+dp[i-2],dp[i-1]);
        }
 
        return max(dp[10004],dp[10003]);
    }
};