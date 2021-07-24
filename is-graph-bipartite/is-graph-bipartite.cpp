class Solution {
public:
    
    bool helper(vector<vector<int>> &graph, int node, vector<int> &visited, int parent, int color){
        
        if(visited[node]) return color == visited[node];
        
        visited[node] = color;
        
        for(auto nbr: graph[node]){
            
            // if(!visited[node]){
                if(!helper(graph,nbr,visited,node,3-color)) return false;
            // }
            
            // else if(nbr!=parent && color==visited[nbr]) return false;
            
        }
        return true;
    }
    
    
    bool dfs(vector<vector<int>> &graph){
        
        vector<int> visited(graph.size(),0);
        
        int color = 1;
        
        for(int i=0; i<graph.size(); i++){
            
            if(!visited[i])
            if(!helper(graph,i,visited, -1, color)) return false;
            
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        return dfs(graph);
    }
};