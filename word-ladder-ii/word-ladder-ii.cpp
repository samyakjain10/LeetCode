class Solution {
public:
    
    vector<vector<string>> ans;
    
        void DFS(string& beginWord, string& endWord, unordered_map<string, unordered_set<string>>& adj, vector<string> &path) {
        path.push_back(beginWord);  //Push current word
        if(beginWord == endWord)
        {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(auto x : adj[beginWord])
            DFS(x, endWord, adj, path);
        
        path.pop_back();    
    }

    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,unordered_set<string>> adj;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        queue<string> q;
        q.push(beginWord);
        
        unordered_map<string,int> visited;
        visited[beginWord] = 0;
        
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            
            string temp = curr;
            
            for(int i=0; i<curr.size(); i++){
                for(char x='a'; x<='z'; x++){
                    
                    //Becomes same word, so skip
                    if(temp[i] == x) continue;
                    
                    temp[i] = x;
                    
                    if(dict.find(temp) != dict.end()){
                        
                        if(visited.count(temp)==0){
                            visited[temp] = visited[curr]+1;
                            q.push(temp);
                            adj[curr].insert(temp);
                        }
                        
                        else if(visited[temp] == visited[curr]+1){
                            adj[curr].insert(temp);
                        }
                        
                    }
                }
                temp[i] = curr[i];
            }
            
        }
        vector<string> path;
        DFS(beginWord,endWord, adj, path);
        return ans;
        
    }
};