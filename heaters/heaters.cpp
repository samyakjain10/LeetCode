class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int minRadius = 0;
        
        for (int i = 0; i < houses.size(); i++) {
            
            auto larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);
    	    int curRadius = INT_MAX;
            
            if (larger != heaters.end())
    	    curRadius = *larger - houses[i];

            if (larger != heaters.begin()) {
                auto smaller = larger - 1;
                curRadius = min(curRadius, houses[i] - *smaller);
            }
            minRadius = max(minRadius, curRadius);
        }
        return minRadius;
    }
};