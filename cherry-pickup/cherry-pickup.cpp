class Solution {
public:
    
    int dp[51][51][51];
    
    int helper(vector<vector<int>>& grid, int r1, int c1, int c2){
        int r2 = r1+c1-c2;
        int n = grid.size();
        if(n == r1 || n == r2 || n == c1 || n == c2 || grid[r1][c1] == -1 || grid[r2][c2] == -1){
            return INT_MIN;
        }
        else if(r1 == n-1 && c1 == n-1){
            return grid[r1][c1];
        }
        else if(dp[r1][c1][c2] != INT_MIN){
            return dp[r1][c1][c2];
        }
        else{
            int ans = grid[r1][c1];
            if(c1!=c2) ans+=grid[r2][c2];
            
            ans += max(max(helper(grid,r1+1,c1,c2),helper(grid,r1,c1+1,c2+1)),max(helper(grid,r1+1,c1,c2+1),helper(grid,r1,c1+1,c2)));
            dp[r1][c1][c2] = ans;
            return ans;
        }
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0; i<51; i++)
            for(int j=0; j<51; j++)
                for(int k=0; k<51; k++)
                    dp[i][j][k] = INT_MIN;
        return max(0,helper(grid,0,0,0));
    }
};