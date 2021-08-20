class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
            
        unordered_set<char> rows[9], cols[9], boxs[9];
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                
                char val = board[i][j];
                
                if(board[i][j] == '.') continue;
                
                if(rows[i].find(val) != rows[i].end()){
                    return false;
                }
                
                if(cols[j].find(val) != cols[j].end()){
                    return false;
                }
                
                int k = (i / 3) * 3 + j / 3;
                
                if(boxs[k].find(val) != boxs[k].end()){
                    return false;
                }
                
                rows[i].insert(val);
                cols[j].insert(val);
                boxs[k].insert(val);
                
            }
        }
        return true;
    }
};