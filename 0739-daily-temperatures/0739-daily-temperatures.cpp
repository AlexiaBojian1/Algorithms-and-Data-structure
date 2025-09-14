class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> stack;
        for(int i = 0;i<temperatures.size();i++) {
            while(!stack.empty() && temperatures[stack.top()]<temperatures[i]){
                int j = stack.top();
                ans[j] = i-j;
                stack.pop();
            }
            stack.push(i);
        }
        return ans;
    }
};