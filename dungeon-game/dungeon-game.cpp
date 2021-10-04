class Solution {
public:
    int m, n;
    int calculateMinimumHP(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int left = 1, right = 1000 * (m+n) + 1, ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isGood(grid, mid)) {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return ans;
    }
    bool isGood(vector<vector<int>>& grid, int initHealth) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = initHealth + grid[0][0];
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r > 0 && dp[r-1][c] > 0)
                    dp[r][c] = max(dp[r][c], dp[r-1][c] + grid[r][c]);
                if (c > 0 && dp[r][c-1] > 0)
                    dp[r][c] = max(dp[r][c], dp[r][c-1] + grid[r][c]);
            }
        }
        return dp[m-1][n-1] > 0;
    }
};