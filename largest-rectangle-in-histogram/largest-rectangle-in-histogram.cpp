class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> lb(n), rb(n);
        
        
        stack<int> s;
        s.push(0);
        lb[0] = -1;
        
        for(int i=1; i<n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty()){
                lb[i] = -1;
            }
            else{
                lb[i] = s.top();
            }
            s.push(i);
        }
        
        stack<int> s1;
        s1.push(n-1);
        rb[n-1] = n;
        
        for(int i=n-2; i>=0; i--){
            while(!s1.empty() && heights[s1.top()] >= heights[i]){
                s1.pop();
            }
            
            if(s1.empty()){
                rb[i] = n;
            }
            else{
                rb[i] = s1.top();
            }
            s1.push(i);
        }
        
        int maxArea = INT_MIN;
        int area, width;
        for(int i=0; i<n; i++){
            width = rb[i]-lb[i]-1;
            area = heights[i]*width;
            maxArea = max(maxArea,area);
        }
        return maxArea != INT_MIN ? maxArea : 0;
    }
};