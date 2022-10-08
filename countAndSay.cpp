class Solution {
public:
    string fun(int n,vector<string> &dp)
    {
        if(n==1)
            return "1";
        if(dp[n]!="-1")
            return dp[n];
        string prev=fun(n-1,dp);
        //time for string compression
        string ans;
        int cnt=1;
        char ele=prev[0];
        //scan elements
        for(int i=1;i<prev.size();i++)
        {
            if(prev[i]==ele)
                cnt++;
            //if not equal change element
            else
            {
                ans=ans+to_string(cnt)+string (1,ele);
                cnt=1;
                ele=prev[i];
            }
        }
        ans=ans+to_string(cnt)+std::string (1,ele);
        return dp[n]=ans;
    }
    string countAndSay(int n) {
        vector<string> dp(31,"-1");
        return fun(n,dp);
    }
};
