class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i+1] && nums[i] != 0) {
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;
            }
        }

        int index = 0;
        for(auto num : nums) {
            if(num != 0) {
                nums[index] = num;
                index++;
            }
        }

        for(int i = index; i < nums.size();i++) {
            nums[i] = 0;
        }

        return nums;
    }
};