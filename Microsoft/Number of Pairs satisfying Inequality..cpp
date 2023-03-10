#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <iostream> 
using namespace __gnu_pbds; 
using namespace std; 

class Solution {
public:
    
//     take advantage of ordered set
    typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, 
            tree_order_statistics_node_update> 
    ordered_set; 
    
    
    long long f(vector<long long>& vt,  long long n, long long k)
{
     long long count=0;
         ordered_set mySet;
        for(long long i=0;i<n;++i){
           
           
            count+=mySet.order_of_key({vt[i]+k,INT_MAX});
              mySet.insert({vt[i],i});  
        }
 
    return count;
}
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        
        // cout<<endl;
        long long n=nums1.size();
        vector<long long> vt(n);
        for(long long i=0;i<n;++i){
            vt[i]=nums1[i]-nums2[i];
        }
        // sort(begin(vt),end(vt));
        return f(vt,n,diff);
        
    }
};
