class Solution {
public:
    
    int helper(string &word1, string &word2, int n, int m){
        
       if(n == 0) return m;
        
        if(m == 0) return n;
        
        if(word1[n-1] == word2[m-1]) return helper(word1,word2,n-1,m-1);
        else{
            return 1+min(helper(word1,word2,n,m-1), min(helper(word1,word2,n-1,m), helper(word1,word2,n-1,m-1)));
        }
        
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
       
        // return helper(word1,word2,n,m);
        
        int dp[n+1][m+1];
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i == 0)
                    dp[i][j] = j;
                
                else if(j == 0)
                    dp[i][j] = i;
                
                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                
                else{
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};