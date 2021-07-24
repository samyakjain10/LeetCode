class Solution {
public:
    bool isValid(string s) {
        stack<char> parent;
        for (char& c : s) {
            switch (c) {
                case '(': 
                case '{': 
                case '[': parent.push(c); break;
                case ')': 
                    if (parent.empty() || parent.top()!='(') return false; 
                    else parent.pop(); break;
                case '}': 
                    if (parent.empty() || parent.top()!='{') return false; 
                    else parent.pop(); break;
                case ']': 
                    if (parent.empty() || parent.top()!='[') return false; 
                    else parent.pop(); break;
                default: ; // pass
            }
        }
        return parent.empty() ;
    }
};