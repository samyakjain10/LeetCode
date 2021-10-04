#include<bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>piles, int h) {
        int n = piles.size();
         if(n == 1)
             return ceil(((double)piles[0]) / ((double)h));
        
        sort(piles.begin(),piles.end());
        int r = 1000000000;
        int l = 1,ans;
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            int c=0;
            for(int i=0;i<n;i++) c+=ceil(((double)piles[i]) / ((double)mid));
             if(c<=h){
                r = mid-1;
            }
            else
                l = mid+1;
        }
        
        return l;
}

int main()
{
    vector<int>piles;
    int h,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        piles.push_back(x);
    }
    cin>>h;
    cout<<minEatingSpeed(piles,h)<<endl;

}