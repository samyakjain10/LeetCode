class Solution {
public:
    
    int n,m;
    
    void DFS(int i,int j, vector<vector<char>>& grid){
        
        //Base Condition
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1') return;
        
        grid[i][j] = '0'; // Mark 0 (visited)
        
        // DFS Neighbours
        DFS(i+1,j,grid);
        DFS(i,j+1,grid);
        DFS(i-1,j,grid);
        DFS(i,j-1,grid);
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        n = grid.size();
        m = grid[0].size();
        
        if(n==0) return 0; // No islands if size of grid is 0
        
        //Loop to traverse all the elements of the grid
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //Count Connected Components
                if(grid[i][j] == '1'){
                    DFS(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};