class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> freq;
        
        for(char c: t){
            freq[c]++;
        }
        
        int cnt = t.length();
        
        int i=0, j=0;
        int minLength = INT_MAX;
        int minStart = -1;
        
        while(j<s.length()){
            
            if(freq[s[j]] > 0)
                cnt--;
            
            freq[s[j]]--;
            
            while(!cnt){
                
                if(j-i+1 < minLength){
                    minLength = j-i+1;
                    minStart = i;
                }
                
                freq[s[i]]++;
                if(freq[s[i]] > 0){
                    cnt++;
                }
                i++;
            }
            j++;
        }
        
        return minLength == INT_MAX ? "" : s.substr(minStart,minLength);
        
    }
};