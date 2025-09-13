class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = nums[0];
        int curr = 0;
        for(int i = 0;i<n;i++) {
            curr  =max(0,curr)+ nums[i];
            maxsum = max(maxsum, curr);
        }
        return maxsum;
    }
};