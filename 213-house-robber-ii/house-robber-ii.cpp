class Solution {
public:
    int rob(vector<int>& nums) {
        int n  = nums.size();
        if( n == 1) {
            return nums[0];
        }
        
        int robFirst = simpleRob(nums, 0, n - 2);
        int robLast = simpleRob(nums, 1, n - 1);
        return max(robFirst, robLast);
    }

    int simpleRob(vector<int> & nums , int start , int end) {
        int n = end - start + 1;
        vector<int> dp(n + 1,0);
        if (n == 1) {
            return nums[start];
        }
        dp[n] = 0;
        dp[n-1] = nums[end];
        for(int i = n - 2; i >= 0; i--) {
            dp[i] = max(dp[i+1] , nums[start + i] + dp[i + 2]);
        }
        return dp[0];
    }
};