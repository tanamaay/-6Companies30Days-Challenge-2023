class Solution {
public:
    
    inline int lastOne(int x) {
        return x & (-x);
    }
    
    void update(vector<int>& a, int i, int delta) {
        for(;i<a.size();i+=lastOne(i)) {
            a[i] += delta; 
        }
    }
    
    int req(vector<int>& a, int i) {
        int ret = 0; 
        for(;i;i-=lastOne(i)) {
            ret += a[i];
        }
        return ret; 
    }
    
    int rsq(vector<int>& a, int l, int r) {
        return req(a,r) - (l == 1?0:req(a,l-1));
    }
    
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size(); 
        vector<int> m(n);
        for(int i=0;i<n;i++) {
            m[nums1[i]] = i;
        }
        long long ret = 0; 
        vector<int> a(n+5);
        vector<int> r(n);
        for(int i = n-1;i>=0;i--) {
            int j = m[nums2[i]];
            r[nums2[i]] = rsq(a,j+1,n+1);
            update(a,j+1,1);
        }
        a.assign(n+5,0);
        for(int i = 0;i<n;i++) {
            int j = m[nums2[i]];
            long long t = req(a,j);
            ret += t * r[nums2[i]];
            update(a,j+1,1);
        }
        return ret; 
    }
};
