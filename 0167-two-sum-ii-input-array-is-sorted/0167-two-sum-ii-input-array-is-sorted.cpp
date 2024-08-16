class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int right = 0;
        int left = numbers.size() -1 ;
        while(right < left) {
            if(numbers[right] + numbers[left] == target) {
                return {right+1, left+1};
            }
            if(numbers[right] + numbers[left] < target) {
                right++;
            }

            if(numbers[right] + numbers[left] > target) {
                left--;
            }
        }
        return {};
    }
};