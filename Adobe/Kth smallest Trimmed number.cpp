class Solution
{
public:
    typedef pair<string, int> pi;
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        int n = nums.size();
        for (auto &q : queries)
        {
            vector<pi> v;
            for (int i = 0; i < n; i++)
            {
                int t = q[1];
                int n1 = nums[i].size();
                string s = nums[i].substr(n1 - t);
                v.push_back({s, i});
            }
            sort(v.begin(), v.end());
            int k = q[0];
            ans.push_back(v[k - 1].second);
        }
        return ans;
    }
};
