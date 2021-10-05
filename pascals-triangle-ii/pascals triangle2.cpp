class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<vector<int>>v;
        vector<int>ans;
       int n=rowIndex+1;
       for(int i=0;i<n;i++)
       {
           vector<int>b;
           for(int j=0;j<=i;j++)
           {
               if(j==0 || j==i)
               {
                 b.push_back(1);   
               }
               else{
                   b.push_back(v[i-1][j-1]+v[i-1][j]);
                   }
           }
           v.push_back(b);
           b.clear();
       }
        for(int j=0;j<n;j++)
        {
            ans.push_back(v[n-1][j]);
        }
        return ans;
    }
        
};