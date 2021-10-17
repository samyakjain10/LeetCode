class Solution {
public:
    bool isNumber(const string& str)
    {
        for (char const &c : str) {
            if (std::isdigit(c) == 0) return false;
        }
        return true;
    }
    int getnum(string &s){
        return stoi(s);
    }
    bool areNumbersAscending(string s) {
        istringstream ss(s);
        string word;
        int prev = -100;
        while(ss>>word){
            if(isNumber(word)){
                int num = getnum(word);
                if(num<=prev) return false;
                prev = num;
            }
        }
        return true;
    }
};