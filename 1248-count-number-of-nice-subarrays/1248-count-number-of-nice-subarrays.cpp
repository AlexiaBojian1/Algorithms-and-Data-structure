class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int curr = 0;
        unordered_map<int, int> freq;
        int res = 0;
        freq[0] = 1;
        for(auto num : nums) {
            curr += num%2;
            res = res + freq[curr - k];
            freq[curr]++;
        }
        return res;
    }
};