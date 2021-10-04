class Solution {
public:
    int maxCoins(vector<int>& a) {
        a.insert(a.begin(), 1);
        a.push_back(1);
        int n = a.size();
        int dp[n][n];
        for (int i = 1; i < n; ++i)
            dp[i][i] = 0;
        for (int l = 2; l < n; ++l) {
            for (int i = 1; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                dp[i][j] = -1e9;
                for (int k = i; k <= j - 1; ++k)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + 
                                  a[i - 1] * a[k] * a[j]);
            }
        }
        // for (int i = 1; i < n; ++i) {
        //     for (int j = 1; j < n; ++j)
        //         cout << dp[i][j] << ' ';
        //     cout << endl;
        // }
        return dp[1][n - 1];
    }
};
