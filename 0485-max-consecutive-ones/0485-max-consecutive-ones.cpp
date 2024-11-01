class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;  // To keep track of the maximum count of consecutive 1s
        int count = 0;     // To keep track of the current count of consecutive 1s

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;  // Increment count for each consecutive 1
                maxCount = max(maxCount, count);  // Update maxCount if the current count is greater
            } else {
                count = 0;  // Reset count if a 0 is encountered
            }
        }
        
        return maxCount;
    }
};
