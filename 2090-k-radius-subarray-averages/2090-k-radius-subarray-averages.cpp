class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0){
            return nums;
        }
        vector<int> result(nums.size(), -1);
        if(2*k+1 > nums.size()){
            return result;
        }
        long long windowSum = 0;
        for (int i = 0; i < (2 * k + 1); ++i) {
            windowSum += nums[i];
        }
        result[k] = windowSum / (2 * k + 1);
        for(int i = (2 * k + 1); i < nums.size();i++) {
            windowSum += nums[i] - nums[i-(2 * k + 1)];
            result[i - k] = windowSum / (2 * k + 1);
        }
        return result;
    }
};