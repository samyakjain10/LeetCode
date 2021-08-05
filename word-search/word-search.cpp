class Solution {
public:
    
    bool dfs(int i, int j, vector<vector<char>>& board, string &word){
        
        int n = word.length();
        
        if(n == 0){
            return true;
        }
        
        if(i<0 || i>= board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0]){
            return false;
        }
        
        char c = board[i][j];
        board[i][j] = '*';
        string temp = word.substr(1);
        
        bool ans = dfs(i-1,j,board,temp) || dfs(i+1,j,board,temp) || dfs(i,j+1,board,temp) || dfs(i,j-1,board,temp); 
        
        board[i][j] = c;
        return ans;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(dfs(i,j,board,word)){
                    return true;
                }
            }
        }
        
        return false;
    }
};