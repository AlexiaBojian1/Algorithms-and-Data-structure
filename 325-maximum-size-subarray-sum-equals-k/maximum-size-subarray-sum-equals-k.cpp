class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long long, int> prefixSum;
        long long sum = 0;
        int ans = 0;
        prefixSum[0] = -1;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(prefixSum.find(sum - k) != prefixSum.end()) {
                ans = max(ans , i - prefixSum[sum - k]);
            }

            if(prefixSum.find(sum) == prefixSum.end()) {
                prefixSum[sum] = i;
            }
        }
        return ans;
    }
};