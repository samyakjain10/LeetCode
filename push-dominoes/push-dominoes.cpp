class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';
        
        string res = "";
        
        int i=0,j=1;
        
        while(j<dominoes.length()){
            
            if(dominoes[j] == '.'){
                j++;
                continue;
            }
            int freq = j-i-1;
            
            if(i>0) res += dominoes[i];
            
            if(dominoes[i] == dominoes[j]){
                res += string(freq, dominoes[i]);
            }
            else if(dominoes[i] == 'L' && dominoes[j] == 'R'){
                res += string(freq,'.');
            }
            else{
                res+= string(freq/2,'R') + string(freq%2,'.') + string(freq/2,'L');
            }
            i=j;
            j++;
        }
        return res;
    }
};