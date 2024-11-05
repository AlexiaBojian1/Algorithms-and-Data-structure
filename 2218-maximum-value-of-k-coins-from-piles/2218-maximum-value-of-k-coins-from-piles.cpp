class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector(k+1,0));
        for(int i = n - 1; i >= 0 ;i--) {
            for(int remain = 1;remain <= k;remain++) {
                dp[i][remain] = dp[i+1][remain];
                int curr = 0;
                int pileSize = piles[i].size();
                for(int j = 0; j < min(pileSize, remain); j++){
                    curr += piles[i][j];
                    dp[i][remain] = max(dp[i][remain], curr + dp[i+1][remain-j-1]);
                }
            }
        }
        return dp[0][k];
    }
};