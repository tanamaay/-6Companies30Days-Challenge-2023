class Solution {
    using i64 = long long;
public:
    static int countPaths(const int n, const vector<vector<int>>& roads) {
        vector<vector<pair<i64, i64>>> adj(n);
        for (auto& i : roads) {
            adj[i[0]].emplace_back(i[1], i[2]);
            adj[i[1]].emplace_back(i[0], i[2]);
        }
        
        priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<>> pq;
        vector<i64> dist(n, LLONG_MAX);
        vector<i64> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        
        pq.emplace(0, 0);
        
        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();
            if (dist[node] < dis)
                continue;
            for (auto [adjNode, edW] : adj[node])
                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    ways[adjNode] = ways[node];
                    pq.emplace(dis + edW, adjNode);
                } else if (dis + edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % 1000000007;
                }
        }
        return int(ways.back());
    }
};
