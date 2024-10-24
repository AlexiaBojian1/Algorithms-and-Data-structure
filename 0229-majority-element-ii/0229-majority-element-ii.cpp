class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int k = nums.size() / 3;
        unordered_map<int, int> freq;
        vector<int> ans;

        // Count frequencies of each element
        for (int num : nums) {
            freq[num]++;
        }

        // Collect elements that appear more than floor(n / 3) times
        for (auto& pair : freq) {
            if (pair.second > k) {
                // Ensure the element is not already in the result
                if (find(ans.begin(), ans.end(), pair.first) == ans.end()) {
                    ans.push_back(pair.first);
                }
            }
        }

        return ans;
    }
};