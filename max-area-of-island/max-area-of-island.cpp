class Solution {
public:
    
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j] || grid[i][j] == 0)
            return 0;
        visited[i][j] = true; 
        return dfs(grid,visited,i+1,j) + dfs(grid,visited,i,j+1) + dfs(grid,visited,i-1,j) + dfs(grid,visited,i,j-1)+1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(),false));
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(visited[i][j] == false && grid[i][j] == 1){
                    int area = dfs(grid,visited,i,j);
                    if(ans < area)
                        ans = area;
                }
            }
        }
        return ans;
    }
};