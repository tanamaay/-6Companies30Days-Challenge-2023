#define ll long long
class Solution {
    
struct SEG {
    vector<vector<ll>> v;
    ll siz = 1;
    
    SEG(ll n, vector<ll> &ar) {
        siz = 1;
        while(siz <= n) siz <<= 1;
        v.resize(2 * siz);
        build(0, siz - 1, 0, ar);
    }
    
    void merge(vector<ll> &a, vector<ll> &b, vector<ll> &c) {
        int i = 0, j = 0;
        while(i < b.size() and j < c.size()) {
            if(b[i] < c[j]) a.push_back(b[i++]);
            else a.push_back(c[j++]);
        }
        while(i < b.size()) {
            a.push_back(b[i++]);
        }
        while(j < c.size()) {
            a.push_back(c[j++]);
        }
    }

    void build(ll lx, ll rx, ll x, vector<ll> &ar) {
        if(lx == rx) {
            if(lx < ar.size()) {
                v[x].push_back(ar[lx]);
            }
            return;
        }
        ll mid = lx + (rx - lx) / 2;
        build(lx, mid, 2 * x + 1, ar);
        build(mid + 1, rx, 2 * x + 2, ar);
 
        merge(v[x], v[2 * x + 1], v[2 * x + 2]);
    }
    
    //count of numbers greater than equal to val
    ll cnt(ll l, ll r, ll val, ll x, ll lx, ll rx) {
        if(lx > r or rx < l) return 0;
        if(lx >= l and rx <= r) {
            int ind = lower_bound(v[x].begin(), v[x].end(), val) - v[x].begin();
            return v[x].size() - ind;
        }
        ll mid = lx + (rx - lx) / 2;
        return cnt(l, r, val, 2 * x + 1, lx, mid) + cnt(l, r, val, 2 * x + 2, mid + 1, rx);
    }
    ll cnt(ll l, ll r, ll val) {
        return cnt(l, r, val, 0, 0, siz - 1);
    }
};
class Solution {
public:
    long long numberOfPairs(vector<int>& a, vector<int>& b, int diff) {
        int n = a.size();
        vector<ll> v(n);
        for(int i = 0; i < n; ++i) v[i] = a[i] - b[i];
        
        SEG tree(n, v);
        
        ll pairs = 0;
        for(int i = 0; i < n; ++i) {
            pairs += tree.cnt(i + 1, n - 1, v[i] - diff);
        }
        return pairs;
    }
};vector<int>g[100005];
    int level_bob[100005];
    bool vis[100005];
    
    int pa[100005];
    
    long long max_amount=-1e9;
    vector<int>Amount;
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        Amount = amount;
        for(auto v: edges){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        
        for(int i=0; i<edges.size()+1; i++) level_bob[i]=1e9;
        memset(vis, false , sizeof(vis));
        level_bob[bob]=0;
        dfs_bob(bob, -1);
        
       
        /// Path from 0 to bob's node and mark these node using map
        map<int, bool>mpp;
        int node=0;
        while(pa[node]!=-1){
            mpp[node]=true;
            node =pa[node];
        }
        mpp[bob]=true;
        
        for(int i=0; i<edges.size()+1; i++)
        {
            if(!mpp[i]){ /// if this node isn't in the bob's path then set level to MAX_INT
                level_bob[i]=1e9;
            }
        }
        
       
        
        memset(vis, false, sizeof(vis)); /// clear vis array
        int level=0;
        long long sum_amount=0;
        dfs_alice(0, level, sum_amount);
        
        return (int)max_amount;
    }
    
    void dfs_bob(int u, int p)
    {
        vis[u]=true;
        pa[u]=p;  /// parent set
        for(auto v: g[u]){
            if(!vis[v]){
                level_bob[v]=level_bob[u]+1; /// level update
                dfs_bob(v, u);
            }
        }
    }
    
    void dfs_alice(int u, int level, long long sum_amount)
    {
        vis[u]=true;
        if(level<level_bob[u]) sum_amount+=Amount[u]; 
        else if(level==level_bob[u]) sum_amount+=(Amount[u]/2); 
     
        if( u!=0 && g[u].size()==1){ 
            max_amount=max(max_amount, sum_amount); 
        }
        for(auto v: g[u]){
            if(!vis[v]){
                dfs_alice(v, level+1, sum_amount);
            }
        }
    }
    
};
