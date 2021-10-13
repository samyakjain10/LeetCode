bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rmax=matrix.size(), cmax=matrix[0].size();
        int r,c,start=0, end=rmax*cmax-1,mid;
        while(start<=end)    //Binary search
        {
            mid=(start+end)/2;  // in 1d array
            r=mid/cmax;
            c=mid-r*cmax;    //finding respective index in matrix
            if(matrix[r][c]>target)
                end=mid-1;
            else if(matrix[r][c]<target)
                start=mid+1;
            else    //number is found
                return true;
        }
        return false;
    }
