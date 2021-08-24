// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        long long l=0, r = n;
        
        long long mid;
        
        while(l<=r){
            mid = (l+r)/2;
            
            if(isBadVersion(mid)){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};