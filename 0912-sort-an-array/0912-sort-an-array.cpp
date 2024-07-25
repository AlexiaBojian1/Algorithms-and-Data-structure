class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int> counts;
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        for(auto & val : nums) {
            counts[val]++;
        }

        int index = 0;
        for(int val = minVal; val <= maxVal; val++) {
            if(counts.find(val) != counts.end()){
                while(counts[val]>0) {
                    nums[index] = val;
                    index++;
                    counts[val] --;
                }
            }
        }
        return nums;
    }
};