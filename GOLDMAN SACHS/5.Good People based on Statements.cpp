class Solution {
public:
    int maximumGood(vector<vector<int>>& A) {
        int N = A.size(), ans = 0;
        auto valid = [&](int m) {
            for (int i = 0; i < N; ++i) {
                if (m >> i & 1) { // person i is good
                    for (int j = 0; j < N; ++j) {
                        int good = m >> j & 1; 
                        if ((A[i][j] == 0 && good) || (A[i][j] == 1 && !good)) 
						return false;
                    }
                }
            }
            return true;
        };
        for (int m = 1; m < (1 << N); ++m) {
            if (valid(m)) ans = max(ans, __builtin_popcount(m));
        }
        return ans;
    }
};
