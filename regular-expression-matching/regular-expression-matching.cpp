class Solution {
public:
    bool isMatch(string s, string p) {
        
        int pn = p.length();
        int sn = s.length();
        
        vector<vector<bool>> dp(pn+1, vector<bool> (sn+1, false));
        
        // Empty Pattern fulfills empty string
        dp[0][0] = true;
        
        //Filling the 1st col
        //True only in case of alternate *
        //e.g. a*b*c*d* as it can make empty string
        for(int i=1; i<=pn; i++){
            if(p[i-1] == '*'){
                dp[i][0] = dp[i-2][0];
            }
        }
        
        for(int i=1; i<=pn; i++){
            
            for(int j=1; j<=sn; j++){
                
                if(p[i-1] == '*'){
                    dp[i][j] = dp[i-2][j];
                    
                    if(p[i-2] == '.' || p[i-2] == s[j-1]){
                        dp[i][j] = dp[i][j] || dp[i][j-1];
                    }
                    
                }
                else if(p[i-1] == s[j-1] || p[i-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
            
        }
        return dp[pn][sn];
    }
    
    bool isMatchRecursive(string s, string p, int i=0, int j=0) {
        
        if(j == p.length()) return i == s.length();
        
        if(p[j+1] == '*'){
            
            // Zero preceding elements
            if(isMatchRecursive(s,p,i,j+2)) return true;
            
            while(i<s.length() && (p[j] == s[i] || p[j] == '.')){
                if(isMatchRecursive(s,p,++i,j+2)) return true;
            }
            
        }
        else if(i<s.length() && (p[j] == '.' || p[j] == s[i]) && isMatchRecursive(s,p,i+1,j+1)){
            return true;
        }
        
        return false;
    }
    
};