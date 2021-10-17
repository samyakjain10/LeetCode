class Solution {
public:
    bool winnerOfGame(string s) {
        int cnta = 0,cntb = 0;
        for(int i = 0;i<s.size();i++){
            int last = i;
            while(last<s.size() && s[last]==s[i]) last++;
            last--;
            if(s[i]=='A'){                
                cnta+=max(0,last-i-1);
            }else{                
                cntb+=max(0,last-i-1);                
            }
            i = last;
            
        }
        if(cnta>cntb) return true;
        return false;
    }
};