class Solution {
public:
    int search(vector<int>& a, int x) {
        int lo = 0, hi = a.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] >= a.front()) {
                auto it = lower_bound(a.begin(), a.begin() + mid + 1, x);
                if (it != a.end() and *it == x)
                    return it - a.begin();
                else
                    lo = mid + 1;
            } else {
                auto it = lower_bound(a.begin() + mid, a.end(), x);
                if (it != a.end() and *it == x)
                    return it - a.begin();
                else
                    hi = mid - 1;
            }
        }
        return -1;
    }
};
