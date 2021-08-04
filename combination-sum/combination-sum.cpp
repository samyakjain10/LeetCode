class Solution {
public:
    
    vector<vector<int>> res;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> temp;
        
        helper(candidates, temp, target, 0);
        return res;
    }
    
    void helper(vector<int>& candidates, vector<int>& temp, int target, int i){
        
        if(target == 0){
            res.push_back(temp);
            return;
        }
        
        if(i>= candidates.size() || target < 0) return;
        
        temp.push_back(candidates[i]);
        helper(candidates, temp, target-candidates[i], i);
        temp.pop_back();
        helper(candidates, temp, target, i+1);
        
    }
    
};