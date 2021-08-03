class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> temp;
    
    void helper(vector<int>& nums, int i, int n, int isPicked){
        
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        
        //Include the element
        if(i == 0 || nums[i-1] != nums[i] || isPicked){
            temp.push_back(nums[i]);
            helper(nums, i+1,n, true);

            //Exclude the element
            temp.pop_back();
        }
            helper(nums,i+1,n, false);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        helper(nums,0,n, true);
        
        return ans;
    }
};