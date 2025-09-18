class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> points;
        int maxim = 0;
        for(int num : nums) {
            points[num] += num;
            maxim = max(maxim, num);
        }
        
        vector<int> dp (maxim+1,0);
        dp[1] = points[1];
        for(int i = 2; i <= maxim; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+points[i]);
        }
        return dp[maxim];
    }
};