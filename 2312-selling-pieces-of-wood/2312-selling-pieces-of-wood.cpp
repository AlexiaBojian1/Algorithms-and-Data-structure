class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        for(const auto& p : prices) {
            int h = p[0];
            int w = p[1];
            long long val = p[2];
            dp[h][w] = max(dp[h][w], val);
        }

        for(int h = 1; h <= m; h++) {
            for(int w = 1; w <= n; w++) {
                for(int k = 1; k <= h / 2; ++k) {
                    dp[h][w] = max(dp[h][w], dp[k][w] + dp[h - k][w]);
                }

                for(int k = 1; k <= w / 2; ++k) {
                    dp[h][w] = max(dp[h][w], dp[h][k] + dp[h][w - k]);
                }
            }
        }
        return dp[m][n];

    }
};