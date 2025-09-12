class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            int compliement  = target - nums[i];
            if(map.find(compliement) != map.end()) {
                result.push_back(i);
                result.push_back(map[compliement]);
            }
            map[nums[i]] = i;
        }
        return result;
    }
};