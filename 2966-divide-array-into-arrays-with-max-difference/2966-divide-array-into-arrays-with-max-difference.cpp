class Solution {
public:
   vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // Step 1: Sort the array to group elements in ascending order
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Result to store the groups
        vector<vector<int>> results;

        // Step 2: Check if the size of the array is divisible by 3
        if (n % 3 != 0) {
            return {};  // Return empty array if size is not divisible by 3
        }

        // Step 3: Iterate through the array in chunks of 3
        for (int i = 0; i < n; i += 3) {
            // Form a group of three elements
            vector<int> group = {nums[i], nums[i+1], nums[i+2]};
            
            // Check if the difference between max and min of the group is <= k
            if (group[2] - group[0] > k) {
                return {};  // Return empty array if the condition fails
            }

            // Add the group to the result
            results.push_back(group);
        }

        return results;
    }
};