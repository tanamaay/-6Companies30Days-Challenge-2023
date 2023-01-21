class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        int M = 1000000007;
        vector<long long> dp(2005, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + delay; j < i + forget; j++)
            {
                dp[j] = (dp[j]% M +  dp[i] % M)%M;
            }
        }

        int ans = 0;
        for (int i = max(0, n - forget); i < n; i++)
            ans = (ans % M + dp[i] % M) % M;
        return ans;
    }
};
