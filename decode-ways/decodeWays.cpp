class Solution {
public:
    int numDecodings(string s) {
        
         int sz=s.size()-1;
        if(s[0]=='0') return 0;
        if(sz==0) return 1;
        int n=sz+1;
       vector<int> dp(n+1,0);
    dp[1]=1;
    dp[0]=1;
    if(s[0]=='0') return 0;
    for(int i=2;i<=n;i++){
        int x=s[i-1]-'0';
        if(x>0) dp[i]=dp[i-1];
        int y=s[i-2]-'0';
        if(y==1||(y==2&&x<7)) dp[i]+=dp[i-2];
    }
    return dp[n];
    }
}; 