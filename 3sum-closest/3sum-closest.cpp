class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int size = nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<size-2; i++){
            int low = i+1, hi = size-1;
            while(low<hi){
                int sum = nums[i] + nums[low] + nums[hi];
                
                if(abs(target-sum)<abs(diff)){
                    diff = target-sum;
                }
            
                if(sum<target) low++;
                else hi--;
                
            }
        }
        return target - diff;
    }
};