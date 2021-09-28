class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        
        if (nums.size() == 1) {
          return nums[0];
        }
        
        if(nums[hi] > nums[0]) return nums[0];
        
        while(lo<=hi){
            int mid = (lo+hi)/2;
            
            if(nums[mid]>nums[mid+1]) return nums[mid+1];
            
            if(nums[mid-1]>nums[mid]){
                return nums[mid];
            }
            
            if(nums[mid] > nums[0]) lo = mid+1;
            else hi = mid-1;
        }return -1;
    }
    
};