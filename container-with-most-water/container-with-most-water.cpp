class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int h = min(height[left], height[right]);
            ans = max(ans, (right - left) * h);
            while (height[left] <= h && left < right) left++;
            while (height[right] <= h && left < right) right--;
        }
        return ans;
    }
};