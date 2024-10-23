class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = 0;
        int maxIndex = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > max) {
                max = nums[i];
                maxIndex = i;
            }
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(max < 2*nums[i] && nums[i] != max){
                return -1;
            }
        }
        return maxIndex;
    }
};