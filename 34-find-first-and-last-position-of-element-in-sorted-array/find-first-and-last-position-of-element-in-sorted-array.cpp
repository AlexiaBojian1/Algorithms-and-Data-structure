class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findleft(nums,target), findright(nums, target)};
    }
private:
    int findleft(const vector<int> & nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int leftinx = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] < target) {
                low = mid + 1;
            } else {
                if(nums[mid] == target) {
                    leftinx = mid;
                }
                high = mid - 1;
            }
        }
        return leftinx;
    }    

    int findright(const vector<int> & nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int rightidx = -1;
        while(low <= high) {
            int mid = low + ( high - low) /2;
            if(nums[mid] > target) {
                high = mid - 1;
            } else {
                if(nums[mid] == target) {
                    rightidx = mid;
                }
                low = mid + 1;
            }
        }
        return rightidx;
    }
};