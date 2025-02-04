class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi = 0;
        unordered_set<int> set(nums.begin(), nums.end());
        
        for(int num : nums) {
            if (!set.count(num - 1)) {  // Start of a new sequence
                int streak = 0;  // Reset streak inside the if condition
                while(set.count(num + streak)) {
                    streak++;
                }
                maxi = max(maxi, streak);
            }
        }
        return maxi;
    }
};
