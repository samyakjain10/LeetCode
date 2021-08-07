class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastidx(26);
        
        for(int i=0; i<s.length(); i++){
            lastidx[s[i]-'a'] = i;
        }
        
        int start = 0, last = 0;
        vector<int> ans;
        for(int i=0; i<s.length(); i++){
            last = max(last, lastidx[s[i]-'a']);
            
            if(i==last){
                ans.push_back(last-start+1);
                start = last+1;
            }
            
        }
        return ans;
    }
};