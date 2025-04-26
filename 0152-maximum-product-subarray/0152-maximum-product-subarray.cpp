class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = nums[0];
        int minprod = nums[0];
        int result = nums[0];

        for(int i = 1 ; i < nums.size(); i++) {
            if(nums[i] < 0) {
                swap(maxprod, minprod);
            }

            maxprod = max(nums[i], nums[i] * maxprod);
            minprod = min(nums[i], nums[i] * minprod);
            result = max(result, maxprod);
        }
        return result;

    }
};