#define pii pair<int, int>
#define maxn 105
#define inf 1000000000

class Solution {
public:
    vector<pii>g[maxn];
    int dis[maxn];

    void dijkstra(int s)
    {
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for(int i=0; i<maxn; i++) dis[i] = inf;
        dis[s] = 0;
        q.push({0, s});
        while(!q.empty()) {
            int u = q.top().second;
            q.pop();
            for(int i=0; i<g[u].size(); i++) {
                int v = g[u][i].first;
                int w = g[u][i].second;
                if(dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto x: times) {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            g[u].push_back({v, w});
        }

        dijkstra(k);

        int ans = 0;
        for(int i=1; i<=n; i++) ans = max(ans, dis[i]);
        if(ans == inf) ans = -1;
        return ans;    
    }
};
