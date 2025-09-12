class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int currincr = 1;
        int currdecr = 1;
        int maxi = 1;
        for(int right = 1; right < nums.size(); right++) {
            if(nums[right] > nums[right - 1] ) {
                currincr++;
                currdecr = 1;
            } else if(nums[right] < nums[right - 1] ){
                currdecr++;
                currincr = 1;
            } else {
                currincr = currdecr = 1;
            }
            maxi = max(max(currincr, currdecr) , maxi);
        }
        return maxi;
    }
};