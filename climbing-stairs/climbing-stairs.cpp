class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        int ans = 0;
        if(n == 1) {
            ans = 1;
        } else if(n==2) {
            ans = 2;
        } else if(n > 2) {
            dp[1] = 1;
            dp[2] = 2;
            for(int i = 3; i<=n; i++) {
                dp[i] = dp[i-1] + dp[i-2];
        }
            
        ans =  dp[n];
        }
     return ans;   
    }
};