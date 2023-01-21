class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        map<char,int>m;
        for(auto x:s){
            m[x]++;
        }
        for(auto x:order){
            if(m.find(x)!=m.end()){
                while(m[x]--){
                    ans+=x;
                }
                
                
            }
        }
        m.clear();
        for(auto x:ans){
            m[x]++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(m.find(s[i])!=m.end()){

            }
            else{
                ans+=s[i];
            }
        }
        return ans;
        
    }
};
