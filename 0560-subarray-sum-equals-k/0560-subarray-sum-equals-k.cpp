class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        counts[0] = 1;
        int ans = 0;
        int curr = 0;
        for(int num:nums) {
            curr = curr+num;
            ans = ans + counts[curr-k];
            counts[curr]++;
        }
        return ans;
    }
};