class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1, d;
        
        if(n == 0 || n == 1) return n;
        
        if(n == 2) return c;
        
        for(int i=3; i<=n; i++){
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};