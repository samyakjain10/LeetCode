int wiggleMaxLength(vector<int>& nums) {
        int p=1,n=1;
        for(int i=1;i<nums.size();i++){
            if((nums[i]-nums[i-1])>0){
                 p=n+1;
            }else if((nums[i]-nums[i-1])<0){
                n=p+1;
                
            }else{
              continue;
            }
        }
        return max(n,p);
    }
