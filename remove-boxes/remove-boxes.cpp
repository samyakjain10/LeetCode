class Solution {
public:
    
    int dp[100][100][100];
    
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memset(dp, 0, sizeof(dp));
        return helper(boxes, 0, n-1, 0);     
    }
    
    int helper(vector<int> &boxes, int l, int r, int k){
        
        if(l>r) return 0;
        
        while(r>l && boxes[r] == boxes[r-1]){
            r--;
            k++;
        }
        
        if(dp[l][r][k] != 0){
            return dp[l][r][k];
        }
        
        dp[l][r][k] = helper(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
        
        for(int i=l; i<r; i++){
            if(boxes[i] == boxes[r]){
                dp[l][r][k] = max(dp[l][r][k], helper(boxes, l, i, k+1) + helper(boxes, i+1, r-1, 0));
            }
        }
        
        return dp[l][r][k];
    }
    
};