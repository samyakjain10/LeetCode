class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        
        if(matrix.size() == 0){
            return ans;
        }
        
        int r1 = 0, r2 = matrix.size()-1;
        int c1 = 0, c2 = matrix[0].size()-1;
        
        while(r1 <= r2 && c1<=c2){
            
            //Add topmost row
            for(int c = c1; c<=c2; c++){
                ans.push_back(matrix[r1][c]);
            }
            
            r1++;
            
            //Add rightmost column
            for(int r=r1; r<=r2; r++){
                ans.push_back(matrix[r][c2]);
            }
            
            c2--;
            
            //Add bottommost row
            
            for(int c = c2; c>=c1 && r1<=r2; c--){
                ans.push_back(matrix[r2][c]);
            }
            
            r2--;
            
            //Add leftmost column
            
            for(int r=r2; r>=r1 && c1<=c2; r--){
                ans.push_back(matrix[r][c1]);
            }
            
            c1++;
            
        }
        return ans;
        
    }
};