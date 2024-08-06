class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> prefix = {nums[0]};
        for(int i=1;i<nums.size();i++) {
            prefix.push_back(prefix.back()+nums[i]);
        }
        return  prefix;
    }
};