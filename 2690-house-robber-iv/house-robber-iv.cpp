class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        while(low <= high) {
            int mid = low + (high - low)/2;
            if(canRob(nums, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    bool canRob(vector<int> & nums, int k , int cap) {
        int count = 0;
        int i = 0;
        int n = nums.size();

        while(i < n) {
            if(nums[i] <= cap) {
                count++;
                i += 2;
            } else {
                i++;
            }
            if(count >= k) return true;
        }
         return count >= k;
    }
};