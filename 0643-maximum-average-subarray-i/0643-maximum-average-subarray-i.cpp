class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = 0;
        double sum = 0;
        for (int i = 0;i < k; i++) {
            sum = sum + nums[i];
        }
        double max = sum;
        for(int i=k;i<nums.size();i++) {
            sum = sum + nums[i];
            sum = sum - nums[i-k];
            if(sum > max)
                max = sum;
        }
        return max/k;
    }
};