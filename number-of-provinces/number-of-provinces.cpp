class Solution {
public:
    
    // We need to find out connected components
    
    void dfs(vector<vector<int>>& isConnected, vector<bool> &visited, int i){
        
        for(int j=0; j<isConnected.size(); j++){
            if(isConnected[i][j] == 1 && !visited[j]){
                visited[i] = true;
                dfs(isConnected, visited, j);
            }
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<bool> visited(isConnected.size(),false);
        
        int cnt = 0;
        
        for(int i=0; i<isConnected.size(); i++){
            if(!visited[i]){
                cnt++;
                dfs(isConnected, visited, i);
            }
        }
        
        return cnt;
    }
};