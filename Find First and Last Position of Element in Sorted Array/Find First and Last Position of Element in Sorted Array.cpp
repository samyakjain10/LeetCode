class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         vector<int>ans;
        
        int low = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int high = upper_bound(nums.begin(),nums.end(),target) - nums.begin() -1;
    
        if(low!=nums.size() && high!=nums.size() && nums[low] == target && nums[high] == target){
        ans.push_back(low);
        ans.push_back(high);    
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        
        return ans;
         
    }
};
