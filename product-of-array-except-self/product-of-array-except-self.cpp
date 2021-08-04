class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> preProd(n,1), postProd(n,1), ans(n,1);
        
        //Compute preProd
        for(int i=1; i<n; i++){
            preProd[i] = preProd[i-1]*nums[i-1];
        }
    
        //Compute postProd
        for(int i=n-2; i>=0; i--){
            postProd[i] = postProd[i+1]*nums[i+1];
        }
        
        for(int i=0; i<n; i++){
            ans[i] = preProd[i] * postProd[i];
        }
        
        return ans;
    }
};