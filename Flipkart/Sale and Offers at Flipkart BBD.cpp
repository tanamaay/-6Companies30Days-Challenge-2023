class Solution {
public:
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,int ind)
    {
        int n = needs.size();
        if(ind<0)
        {
            int ans =0;
            
            for(int i=0;i<needs.size();i++)
            {
                ans += needs[i]*price[i];
            }   
            return ans;
        }
        else
        {
            bool lte = true;
            
            for(int i=0;i<n;i++)
            {
                if(needs[i]<special[ind][i])
                {
                    lte = false;
                    break;
                }
            }
            if(lte)
            {
                //op1
                int op1 = solve(price,special,needs,ind-1);
                
                
                //op2
                int op2 = 0;
                for(int i=0;i<n;i++)
                {
                    needs[i] = needs[i] - special[ind][i];
                }
                
                op2 = special[ind][n] + solve(price,special,needs,ind);
                
                for(int i=0;i<n;i++)
                {
                    needs[i] = needs[i] + special[ind][i];
                }
                
                return min(op1,op2);
            }
            else
            {
                return solve(price,special,needs,ind-1);
            }
        }
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int ind=special.size()-1;
        return solve(price,special,needs,ind);
    }
};
