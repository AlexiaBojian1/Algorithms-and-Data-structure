class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0); 
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            diff[l] += 1;
            if (r + 1 < n) {
                diff[r + 1] -= 1;
            }
        }
       
        int currentDecrement = 0;
        for (int i = 0; i < n; i++) {
            currentDecrement += diff[i];
            if (nums[i] > currentDecrement) {
                return false;
            }
        }
        
        return true; 
    }
    
};