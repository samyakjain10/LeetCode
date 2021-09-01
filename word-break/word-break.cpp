class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        
        int n = s.length();
        
        if(n == 0) return false;
        
        vector<bool> dp(n+1, false);
        
        dp[0] = true;
        
        for(int i=1; i<=n; i++){
            
            for(int j=i-1; j>=0; j--){
                
                if(dp[j]){
                    string word = s.substr(j,i-j);
                    if(st.find(word) != st.end()){
                        dp[i] = true;
                        break;
                    }
                }
                
            }
            
        }
        return dp[n];
    }
};