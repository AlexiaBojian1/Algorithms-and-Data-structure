class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) return 0;   
        if (n == 1) return k;
        vector<long long> dp(n + 1, 0);
    
        dp[1] = k;
        dp[2] = k * k;
        for(int i = 3; i <= n; i++) {
            dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
        }
        return dp[n];
    }
};