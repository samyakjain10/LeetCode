class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256,-1);
        
        int maxLen = 0;
        int start = -1;
        
        for(int i=0; i != (int)s.length(); i++){
            if(last[s[i]] > start){
                start = last[s[i]];
            }
            last[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }
};
