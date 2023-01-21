class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int rows = dungeon.size(), cols = dungeon[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX)); // Initialize dp array with maximum value
    dp[rows-1][cols-1] = max(1, 1 - dungeon[rows-1][cols-1]); // Initialize last cell of dp array
    for(int i = rows-2; i >= 0; i--) {
dp[i][cols-1] = max(1, dp[i+1][cols-1] - dungeon[i][cols-1]); // Initialize last column of dp array
    }
    for(int i = cols-2; i >= 0; i--) {
dp[rows-1][i] = max(1, dp[rows-1][i+1] - dungeon[rows-1][i]); // Initialize last row of dp array
    }
    // fill the dp array
    for(int i=rows-2; i>=0; i--) {
        for(int j=cols-2; j>=0; j--) {
            dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
        }
    }
    
    return dp[0][0];
}
};
