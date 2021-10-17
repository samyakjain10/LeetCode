class Solution {
public:
    int res;
    int mx;
    
    void generate(vector<int>&nums,int n,int maxPossible){
        if(n==0){
            if(maxPossible==res){
                mx++;
            }
            else if(res< maxPossible){
                mx = 1;
                res = maxPossible;
            }
            return;
        }
        
        generate(nums,n-1,maxPossible|nums[n-1]);
        generate(nums,n-1,maxPossible);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        mx = 0;
        res =0;
        generate(nums,nums.size(),0);
        return mx;
    }
};