class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int currstreak = 0;
        int maxstreak = 0;
        for(int num : num_set) {
            if(!num_set.count(num - 1)) {
                currstreak = 1;
                int currnum = num;
                while(num_set.count(currnum + 1)) {
                    currstreak++;
                    currnum++;
                }

                maxstreak = max(currstreak, maxstreak);
            }
        }
        return maxstreak;
        
    }
};