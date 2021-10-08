class Solution {
public:
    int intmax = 1e5;
    typedef pair<int,int> pii;
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dest, int K) {
        vector<pii> adj[n];
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, intmax);
        dist[src] = 0;
        queue<pii> q;
        q.push({0, src});
        int ans = 1e8;
        while (!q.empty() and K-- >= 0) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [dist_node, node] = q.front();
                q.pop();
                for (auto [nbr, d] : adj[node]) {
                    if (dist[nbr] > d + dist_node) {
                        dist[nbr] = d + dist_node;
                        q.push({dist[nbr], nbr});
                    }
                    if (nbr == dest)
                        ans = min(ans, dist[nbr]);
                }
            }
        }
        return ans == 1e8 ? -1 : ans;
    }
};
