class Solution {
public:
    
    vector<string> ans;
    string temp = "";
    
    bool isAlphabet(char c){
        return (c>='a' && c<='z')||(c>='A'&&c<='Z');
    }
    
    void helper(string s, int i, int n){
        
        if(i == n){
            ans.push_back(temp);
            return;
        }
        
        if(isAlphabet(s[i])){
            
            temp+=tolower(s[i]);
            helper(s,i+1,n);
            temp.pop_back();
            temp+=toupper(s[i]);
            helper(s,i+1,n);
            temp.pop_back();
        }
        else{
            
            temp+=s[i];
            helper(s,i+1,n);
            temp.pop_back();
        }
        
    }
    
    vector<string> letterCasePermutation(string s) {
        
        int n = s.length();
        
        if(n == 0) return ans;
        helper(s, 0, n);
        
        return ans;
    }
};