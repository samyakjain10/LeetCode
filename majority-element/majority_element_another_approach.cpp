class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i,count=1,ans=nums[0];
        for(i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                count++;
            }
            else
            {
                count=1;
            }
            if(count>(nums.size()/2))
            {
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};
