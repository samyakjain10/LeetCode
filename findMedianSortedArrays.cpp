class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size())
            return findMedianSortedArrays(b, a);
        int m = a.size(), n = b.size(), req = (m + n + 1) / 2;
        int lo = 0, hi = m;
        while (lo <= hi) {
            int cut1 = lo + (hi - lo) / 2;
            int cut2 = req - cut1;
            int l1 = (cut1 == 0 ? INT_MIN : a[cut1 - 1]);
            int l2 = (cut2 == 0 ? INT_MIN : b[cut2 - 1]);
            int r1 = (cut1 == m ? INT_MAX: a[cut1]);
            int r2 = (cut2 == n ? INT_MAX : b[cut2]);
            if (l1 <= r2 and l2 <= r1) {
                if ((m + n) & 1)
                    return max(l1, l2);
                else
                    return ((double) max(l1, l2) + min(r1, r2)) / 2;
            } else if (l1 > r2) {
                hi = cut1 - 1;
            } else {
                lo = cut1 + 1;
            }
        }
        return -1;
    }
};
