class Solution {
public:
    
    void dfslagao(vector<vector<int>>& image, int i, int j,int colour, int newColor){
        
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size() || image[i][j] != colour || image[i][j] == newColor)
            return;
        
        image[i][j] = newColor;
        dfslagao(image,i+1,j,colour,newColor);
        dfslagao(image,i,j+1,colour,newColor);
        dfslagao(image,i-1,j,colour,newColor);
        dfslagao(image,i,j-1,colour,newColor);

    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int sourceColour = image[sr][sc];
        dfslagao(image,sr,sc,sourceColour,newColor);
        return image;
    }
};