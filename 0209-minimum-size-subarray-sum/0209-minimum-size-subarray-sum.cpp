class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
         int res = INT_MAX;
         int sum =0;
         while(right<nums.size()) {
             sum=sum+nums[right];
             while(sum>= target) {
                 res = min(res,right-left+1);
                 sum=sum-nums[left];
                 left++;
             }
             right++;
         }
         return (res != INT_MAX) ? res : 0;
    }
};