class Solution {
public:
    int minimumCardPickup(vector<int>& v) {
        int n = v.size();
        int ans = INT_MAX;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(m.find(v[i])!=m.end()){
                ans = min(ans,i-m[v[i]]+1);
            }
            m[v[i]] = i;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
