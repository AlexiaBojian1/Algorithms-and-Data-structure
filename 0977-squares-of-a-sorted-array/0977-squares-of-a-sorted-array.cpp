class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n =  nums.size();
        int left = 0;
        int right = n -1;
        vector<int> results(n);
        for(int i = n -1  ; i>=0; i--) {
            int square;
            if(abs(nums[left]) < abs(nums[right])) {
                square = nums[right];
                right --;
            } else {
                square = nums[left];
                left++;
            }
            results[i] = square * square;
        }
        return results;
    }
};