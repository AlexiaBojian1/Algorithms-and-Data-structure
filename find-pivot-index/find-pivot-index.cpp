class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int sum = 0;
        for(int num : nums) {
            sum = sum + num;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(left == sum - left - nums[i]) return i;
            left = left + nums[i];
        }
        return -1;
    }
};