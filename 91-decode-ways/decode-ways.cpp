class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = (s[0] == '0') ? 0 : 1;
        for(int i = 2; i <= n; i++) {
            int onedigit = stoi(s.substr(i - 1, 1));
            if(onedigit >= 1 && onedigit <= 9) {
                dp[i] += dp[i-1];
            }

            int twodigit = stoi(s.substr(i - 2, 2));
            if(twodigit >= 10 && twodigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};