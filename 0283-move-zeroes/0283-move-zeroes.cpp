class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for(auto num : nums) {
            if(num != 0){
                nums[left] = num;
                left++;
            }
        }
        for(int i = left; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};