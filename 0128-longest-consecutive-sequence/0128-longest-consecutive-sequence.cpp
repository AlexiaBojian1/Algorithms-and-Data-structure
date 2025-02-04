class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set (nums.begin(),nums.end());
        int streak = 0;
        int maxi = 0;
        for(int num : nums) {
            if(!set.count(num-1)) {
                streak = 0;
                while(set.count(num+streak)) {
                    streak++;
                }
                maxi = max(maxi,streak);
            }
        }
        return maxi;
    }
};