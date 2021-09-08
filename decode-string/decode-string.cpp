class Solution {
public:
    
    bool isDigit(char c) {
        return c - '0' >= 0 && c - '0' <= 9;
    }
    int i=0;
    string decodeString(string s) {
        string res = "", num = "";;
        
        while(i<s.length()){
            
            if(isDigit(s[i])){
                num += s[i];
            }
            else if(s[i] == '['){
                i++;
                string temp = decodeString(s);
                
                for(int j=1; j<=stoi(num); j++){
                    res+=temp;
                }
                num = "";
            }
            else if(s[i] == ']'){
                return res;
            }
            else{
                res += s[i];
            }
            i++;
        }
        return res;
    }
};