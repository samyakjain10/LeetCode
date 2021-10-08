class Solution {
public:
    int m, n, idiff[4] = {0, 1, 0, -1}, jdiff[4] = {1, 0, -1, 0};
    vector<vector<int>> dp;
    vector<vector<bool>> visited;
    bool isValid(int i, int j) {
        return i >= 0 and j >= 0 and i < n and j < m;
    }
    void dfs(vector<vector<int>>& matrix, int i, int j) {
        for (int k = 0; k < 4; ++k) {
            int nexti = i + idiff[k], nextj = j + jdiff[k];
            if (isValid(nexti, nextj) == true and
                                matrix[i][j] < matrix[nexti][nextj]) {
                if (visited[nexti][nextj] == false)
                    dfs(matrix, nexti, nextj);
                dp[i][j] = max(dp[i][j], 1 + dp[nexti][nextj]);
            }
        }
        visited[i][j] = true;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 1;
        n = matrix.size(), m = matrix[0].size();
        dp.assign(n, vector<int> (m, 1));
        visited.assign(n, vector<bool> (m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visited[i][j] == false)
                    dfs(matrix, i, j);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
