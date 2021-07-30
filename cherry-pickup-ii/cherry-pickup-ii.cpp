class Solution {
public:
    
    int dp[80][80][80];
    
    int helper(vector<vector<int>>& grid, int c1, int c2, int r){
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(r==n) return 0;
        if(dp[c1][c2][r] != -1) return dp[c1][c2][r];
        
        int ans = 0;
        for(int i=c1-1; i<=c1+1; i++){
            for(int j=c2-1; j<=c2+1; j++){
                if(i>=0 && i<m && j>=0 && j<m){
                    ans = max(ans, helper(grid,i,j,r+1));
                }
            }
        }
        if(c1 == c2) ans+=grid[r][c1];
        else ans+=(grid[r][c1] + grid[r][c2]);
        return dp[c1][c2][r] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        return helper(grid,0,m-1,0);
    }
};