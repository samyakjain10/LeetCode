class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        int reachable = 0;
        
        for(int i=0; i<n; i++){
            if(i>reachable){
                return false;
            }
            reachable = max(reachable, i+nums[i]);
        }
        return true;
    }
};