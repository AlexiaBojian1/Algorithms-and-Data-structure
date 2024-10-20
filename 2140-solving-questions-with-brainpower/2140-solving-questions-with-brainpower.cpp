class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long> dp(n+1);
        for(int i = n-1; i>=0;i--) {
            int j = i+ questions[i][1] + 1;
            dp[i] = max(questions[i][0] + dp[min(j,n)] , dp[i+1]);
        }
        return dp[0];
    }
};