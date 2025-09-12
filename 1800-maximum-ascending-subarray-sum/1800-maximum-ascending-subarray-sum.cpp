class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int curr = nums[0];
        int maxi = nums[0];
        for(int right = 1; right < nums.size(); right++) {
            if(nums[right] > nums[right-1]) {
                curr += nums[right];
            } else {
                curr = nums[right];
            }
            maxi = max(maxi , curr);
        }
        return maxi;
    }
};