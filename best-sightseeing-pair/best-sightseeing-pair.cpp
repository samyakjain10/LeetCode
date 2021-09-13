class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0, cur = 0;
        
        for(int val: values){
            
            res = max(res, cur+val);
            cur = max(cur,val)-1;
            
        }
        return res;
    }
};