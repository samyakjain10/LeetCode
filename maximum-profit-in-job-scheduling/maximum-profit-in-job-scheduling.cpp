class Solution {
public:
    
    int latestNonConflict(vector<vector<int>> &jobs, int index){
        int lo = 0, hi = index - 1;
 
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid][0] <= jobs[index][1])
        {
            if (jobs[mid + 1][0] <= jobs[index][1])
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }
  
    return -1;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        
        int *table = new int[n];
        table[0] = jobs[0][2];        
        
        for (int i=1; i<n; i++){
            int inclProf = jobs[i][2];
            int l = latestNonConflict(jobs, i);
            
            if (l != -1)
                inclProf += table[l];
 
            table[i] = max(inclProf, table[i-1]);
        }
 
    return table[n-1];
    }
};