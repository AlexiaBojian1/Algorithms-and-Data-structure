class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int best = nums[0] + nums[1] + nums[2];
        
        for(int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while(l < r) {
                long long sum = (long long)nums[i] + nums[l] + nums[r];
                if (abs((long long)target - sum) < abs((long long)target - best)) {
                    best = (int)sum;
                }

                if(sum < target) {
                    l++;
                }else if(sum > target) {
                    r--;
                } else {
                    return target;
                }

            }

        }
        return best;
        
    }
};