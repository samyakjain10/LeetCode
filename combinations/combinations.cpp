class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> temp;
    
    void helper(int n, int k, int i){
        
        if(k == 0){
            ans.push_back(temp);
            return;
        }
        
        if(i > n || k<0){
            return;
        }
        
        temp.push_back(i);
        helper(n,k-1,i+1);
        temp.pop_back();
        helper(n,k,i+1);
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        helper(n,k,1);
        return ans;
    }
};