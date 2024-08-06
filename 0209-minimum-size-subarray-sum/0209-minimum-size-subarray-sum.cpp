class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int curr = 0;
        int ans = INT_MAX;
        int left = 0;
        for(int right = 0; right < nums.size(); right++) {
            curr = curr + nums[right];
            while(curr >= target) {
                ans =  min(ans, right-left+1);
                curr = curr - nums[left];
                left++;
            }
        }
        return (ans!= INT_MAX) ? res : 0;
    }
};