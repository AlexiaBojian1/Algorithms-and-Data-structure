class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1;
        int k = 0;
        for(int i=1;i<nums.size();i++) {
            if(nums[i-1] == nums[i]) {
                k++;
            }
            
            if(nums[i-1] != nums[i]) {
                k=0;
            }
            if(k<=1) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};