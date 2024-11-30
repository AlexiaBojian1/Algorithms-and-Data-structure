class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res; // store unique triplets
        unordered_set<int> dups; // keep track of duplicates
        unordered_map<int, int> seen; // key = values of array , value = index

        for(int i = 0;i < nums.size(); i++) {
            if(dups.insert(nums[i]).second)  // true is nums[i] is not in dups
            {
                for(int j = i+1; j < nums.size() ; j++) {
                    int complement = -nums[i] - nums[j];
                    auto it = seen.find(complement);
                    if(it != seen.end() && it->second == i) {
                        vector<int> triplet = {nums[i], nums[j], complement};
                        sort(begin(triplet), end(triplet));
                        res.insert(triplet);
                    }
                    seen[nums[j]] = i;
                }
            }
        }
        return vector<vector<int>>(begin(res), end(res));

    }
};