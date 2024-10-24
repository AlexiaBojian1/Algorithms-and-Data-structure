class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        int leftsum = 0;
        int leftcount = 0;
        int rightsum = 0;
        int rightcount = 0;
        vector<int> ans;
        for(int i = 0;i<nums.size();i++) {
            rightsum = totalsum - nums[i] - leftsum;
            leftcount = i;
            rightcount = nums.size() - 1 - i;

            int lefttotal = leftcount * nums[i] - leftsum;
            int righttotal = rightsum - rightcount* nums[i];

            ans.push_back(lefttotal+righttotal);
            leftsum = leftsum + nums[i];
        }
        return ans;
    }
};