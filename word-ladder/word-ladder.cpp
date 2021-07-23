class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        //Base Case
        if(beginWord == endWord){
            return 0;
        }
        
        unordered_set<string> s(wordList.begin(), wordList.end());
        
        //If endWord is not in dictionary
        if(s.find(endWord) == s.end()){
            return 0;
        }
        
        int ans = 0,n = beginWord.size();
        
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()){
            ans++;
            
            int sz = q.size();
            
            while(sz--){
                string word = q.front();
                q.pop();
                
                for(int pos = 0; pos<n; pos++){
                    char original_char = word[pos];
                    
                    for(char c='a'; c<='z'; c++){
                        word[pos] = c;
                        
                        if(word == endWord) return ans+1;
                        
                        if(s.find(word) == s.end()) continue;
                        
                        s.erase(word);
                        
                        q.push(word);
                        
                    }
                    word[pos] = original_char;
                }
                
            }
            
        }
        return 0;
    }
};