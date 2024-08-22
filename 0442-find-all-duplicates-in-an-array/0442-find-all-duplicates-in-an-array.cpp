class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> seen;
        vector<int> result;
        for(int num : nums) {
            if(seen.find(num) != seen.end()){
                result.push_back(num);
            }
            seen.insert(num);
        }
        return result;
    }
};