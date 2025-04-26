class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<double> set;
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            double avg = 0;
            avg = (nums[left] + nums[right])/2.0;
            set.insert(avg);
            left++;
            right--;
        }
        return set.size();
    }
};