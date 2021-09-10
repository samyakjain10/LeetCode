class Solution {
public:
    
    int helper(vector<int>& nums, vector<int>& dp, int pos){
        
        if(pos>=(int)nums.size()-1) return 0;
        
        if(dp[pos] != 10000) return dp[pos];
        
        for(int i=1; i<=nums[pos]; i++){
            dp[pos] = min(dp[pos],1+helper(nums,dp,pos+i));
        }
        return dp[pos];
    }
    
    int jump(vector<int>& nums) {
     vector<int> dp(size(nums), 10000); 
	return helper(nums, dp, 0);   
    }
};