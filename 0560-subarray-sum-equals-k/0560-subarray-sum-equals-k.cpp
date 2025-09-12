class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int curr = 0;
        int res = 0;
        for(auto num : nums) {
            curr += num;
            res = res + freq[curr - k];
            freq[curr]++;
        }
        return res;
    }
};