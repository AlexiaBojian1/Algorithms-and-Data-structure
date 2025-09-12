class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double curr = 0;
        for(int i = 0; i < k;i++) {
            curr = curr + nums[i];
        }
        double best = curr;
        for(int i = k;i<nums.size();i++) {
            curr = curr + nums[i] - nums[i-k];
            if(curr > best) {
                best = curr;
            }
        }
        return best / k;
    }
};