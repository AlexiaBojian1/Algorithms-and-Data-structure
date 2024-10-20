class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) {
            return 0;
        }
        vector<int> maxRobbed (N+1);
        maxRobbed[N] = 0;
        maxRobbed[N-1] = nums[N-1];
        for(int i = N-2; i >=0;i--) {
            maxRobbed[i] = max(maxRobbed[i+1], nums[i] + maxRobbed[i+2]);
        }
        return maxRobbed[0];
    }
};