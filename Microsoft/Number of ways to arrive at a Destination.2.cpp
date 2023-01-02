int countPaths(int n, vector<vector>& roads)
{
vector<pair<long long,long long>>adj[n];
for(auto it :roads)
{
adj[it[0]].push_back({it[1],it[2]});
adj[it[1]].push_back({it[0],it[2]});
}
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
vectorways(n,0);
vectordist(n,LONG_MAX);
ways[0]=1;
dist[0]=0;
long long mod=(long long)(1e9+7);
pq.push({0,0});
while(!pq.empty())
{
auto it =pq.top();
long long dis=it.first;
long long node=it.second;
pq.pop();

        for(auto it:adj[node])
        {
            long long adjnode=it.first;
              long long ew=it.second;
            if(ew+dis<dist[adjnode])
            {
               dist[adjnode]=ew+dis;
                ways[adjnode]=ways[node];
                pq.push({ew+dis,adjnode});
            }
            else if(ew+dis==dist[adjnode])
            {
                 ways[adjnode]=(ways[node]+ ways[adjnode])%mod;
            }
        }
    }
    return (ways[n-1])%mod;
