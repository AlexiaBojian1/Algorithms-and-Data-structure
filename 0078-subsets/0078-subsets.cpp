class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr = {};
        backtrack(ans,0,  curr,nums);
        return ans;
    }

    void backtrack(vector<vector<int>>& ans, int i,vector<int>& curr, vector<int>& nums) {
        if(i > nums.size()) {
            return;
        }

        ans.push_back(curr);
        for(int j = i;j< nums.size();j++ ) {
            curr.push_back(nums[j]);
            backtrack(ans, j+1,curr,nums);
            curr.pop_back();
        }
    }
};