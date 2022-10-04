class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int dp[m][n];
        
        dp[0][0] = 1;
        
        for(int i=1; i<m; i++){
            dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1) ? 1 : 0;
        }
        
        for(int i=1; i<n; i++){
            dp[0][i] = (obstacleGrid[0][i] == 0 && dp[0][i - 1] == 1) ? 1 : 0;
        }
        
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(!obstacleGrid[i][j])
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
                else
                    dp[i][j] = 0;
            }
        }
        return dp[m-1][n-1];
    }
};
