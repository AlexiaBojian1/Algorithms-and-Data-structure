class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(0, curr, ans, nums);
        return ans;
    }

    void backtrack( int i, vector<int> & curr, vector<vector<int>> & ans, vector<int> & nums) {
        if(i > nums.size()) {
            return;
        }

        ans.push_back(curr);
        for(int j = i; j < nums.size(); j++) {
            curr.push_back(nums[j]);
            backtrack(j + 1, curr, ans, nums);
            curr.pop_back();
        }
    }
};