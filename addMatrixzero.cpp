class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        bool row0 = false, col0 = false;
        if (find(a[0].begin(), a[0].end(), 0) != a[0].end())
            row0 = true;
        for (int i = 0; i < n; ++i) {
            if (a[i][0] == 0)
                col0 = true;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (a[i][j] == 0)
                    a[0][j] = a[i][0] = 0;
            }
        }
        for (int i = 1; i < n; ++i) {
            if (a[i][0] == 0)
                a[i].assign(m, 0);
        }
        for (int j = 1; j < m; ++j) {
            if (a[0][j] == 0) {
                for (int i = 1; i < n; ++i)
                    a[i][j] = 0;
            }
        }
        if (row0 == true)
            a[0].assign(m, 0);
        if (col0 == true) {
            for (int i = 0; i < n; ++i)
                a[i][0] = 0;
        }
    }
};
