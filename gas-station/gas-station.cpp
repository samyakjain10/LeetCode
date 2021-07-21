class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int netFuel = 0;
        int n = gas.size();
        
        for(int i=0; i<n; i++){
            netFuel += (gas[i] - cost[i]);
        }
        
        // If diff between total fuel and total cost is less than 0, 
        // then answer doesn't exist
        if(netFuel < 0) return -1; 
        
        int start = 0;
        
        int balance = 0;
        
        for(int i=0; i<n; i++){
            balance += (gas[i] - cost[i]);
            if(balance<0){
                balance = 0;
                start = i+1;
            }
        }
        return start;
        
    }
};