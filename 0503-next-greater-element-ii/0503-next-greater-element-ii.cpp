class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n ,- 1);
        stack<int> stack;

        for(int i = 0; i < 2 * n ; i++) {
            int current = nums[i % n];

            while(!stack.empty() && nums[stack.top()] < current) {
                result[stack.top()] = current;
                stack.pop();
            }

            if(i < n) {
                stack.push(i);
            }
        }
        return result;
    }
};