class Solution {
public:
    int minStartValue(vector<int>& nums) {
        vector<int> prefix = {nums[0]};
        int mini = nums[0];
        for(int i=1; i < nums.size();i++) {
            prefix.push_back(prefix.back() + nums[i]);
            mini = min(mini, prefix.back());
        }
        int ans =  1 - mini;
        return (ans > 0) ? ans : 1;
    }
};