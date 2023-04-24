// Contributed by Manan Bansal

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>ans(cost.size());
        ans[cost.size()-1]=cost[cost.size()-1];
        ans[cost.size()-2]=cost[cost.size()-2];
        for(int i=cost.size()-3;i>=0;i--)
        {
            ans[i]=cost[i]+min(ans[i+1],ans[i+2]);
        }
        return min(ans[0],ans[1]);
    }
};
