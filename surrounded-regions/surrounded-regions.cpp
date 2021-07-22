class Solution {
public:
    
    // We traverse over boundary and check for board[i][j] == 'O'
    // If board[i][j] == 'O', we mark it as #
    // We make a DFS call and similarly check for all neighbours of board[i][j]
    
    void check(vector<vector<char>>& board, int i, int j, int row, int col){
        
        if(board[i][j] == 'O'){
            board[i][j] = '#';
            
            if(i>1) check(board,i-1,j,row,col);
            if(j>1) check(board,i,j-1,row,col);
            if(i+1<row) check(board, i+1, j, row, col);
            if(j+1<col) check(board, i, j+1, row, col);
            
        }
        
    }
    
    void solve(vector<vector<char>>& board) {
        
        int row=board.size();
        if(row == 0)
        	return;
        int col=board[0].size();
        
        for(int i=0; i<row; i++){
            check(board,i,0,row,col);
            if(col > 1) check(board,i,col-1,row,col);
        }
        
        for(int i=1; i+1<col; i++){
            check(board,0,i,row,col);
            if(row > 1) check(board,row-1,i,row,col);
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
        
    }
};