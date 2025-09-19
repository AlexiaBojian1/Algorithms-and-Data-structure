class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int maxsum = nums[0];
        for(int num : nums) {
            curr = max(curr, 0) + num;
            maxsum = max(maxsum, curr);
        }
        return maxsum;
    }
};