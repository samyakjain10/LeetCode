class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        
        int ans = 0, n = nums.size();
        
        
        for(int i=0; i<n; i++){
            
            // If element not visited
            if(nums[i] != INT_MAX){
                int s = nums[i], cnt = 0;
                
                while(nums[s] != INT_MAX){
                    int temp = s;
                    s = nums[s];
                    cnt++;
                    nums[temp] = INT_MAX;
                }
                ans = max(ans, cnt);
            }
            
        }
        return ans;
    }
};