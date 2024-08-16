class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;
        int l = 1;
        int count = 1;
        for(int r = 1;r < nums.size(); r++) {
            if(nums[r] == nums[r-1]) {
                if(count < k) 
                    nums[l++] = nums[r];
                count++;    
            }else {
                count ++;
                nums[l++] = nums[r];
            }
        }
        return l;
    }
};