class Solution {
public:
    int solve(int i,string &s,int *dp)
    {
        if(i>=s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        int x1=s[i]-48,x2=0;
        if(i<s.size()-1)
        {
            x2=x1*10 + s[i+1]-48;
        }
        if(x1>0)ans+=solve(i+1,s,dp);
        if(x1>0 and x2>0 and x2<=26)ans+=solve(i+2,s,dp);
            return dp[i]=ans;
    }
    int numDecodings(string s) {
        int dp[101];
        memset(dp,-1,sizeof(dp));
        return solve(0,s,dp);
        
    }
};