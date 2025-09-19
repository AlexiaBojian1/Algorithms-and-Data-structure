class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;

        const int INF = 1000000000;
        vector<vector<int>> dp(n, vector<int>(d + 1, INF));

        dp[n - 1][d] = jobDifficulty[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            dp[i][d] = max(dp[i + 1][d], jobDifficulty[i]);
        }

        for(int day = d - 1; day > 0; day--) {
            for(int i = day - 1; i < n - (d - day); i++) {
                int hardest = 0;
                for(int j = i; j < n - (d - day); j++) {
                    hardest = max(hardest, jobDifficulty[j]);
                    dp[i][day] = min(dp[i][day], hardest +  dp[j + 1][day + 1]);
                }
            }
        }
        return dp[0][1];
    }
};