class Solution {
public:
    bool isMatch(string str, string pattern) {
        int n1 = str.size(), n2 = pattern.size();
        vector<vector<bool>> dp(n1 + 1, vector<bool> (n2 + 1, false));
        dp[0][0] = true;
        for (int j = 0; j < n2 and pattern[j] == '*'; ++j) {
            // if (pattern[j] == '*')
                dp[0][j + 1] = true;
        }
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (pattern[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
                else
                    dp[i][j] = dp[i - 1][j - 1] and 
                (str[i - 1] == pattern[j - 1] or pattern[j - 1] == '?'); 
            }
        }
        // for (int i = 0; i <= n1; ++i) {
        //     for (int j = 0; j <= n2; ++j)
        //         cout << dp[i][j] << ' ';
        //     cout << '\n';
        // }
        return dp[n1][n2];
    }
};
/*
1 0 0 0 0 0
0 1 1 0 0 0
0 0 1 1 1 0
0 0 0 0 1 1
*/
