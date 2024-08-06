class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int l = 0;
        int r = k -1;
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        while(r< nums.size()) {
            ans = min(ans, nums[r] - nums[l]);
            l++;
            r++;
        }
        return ans;
    }
};