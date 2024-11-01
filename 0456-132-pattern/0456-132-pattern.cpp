class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>> s;
        int currmin = nums[0];

        for(int i = 0;i< nums.size();i++) {
            while(!s.empty() && s.top().first <= nums[i]) {
                s.pop();
            }
            if(!s.empty() && s.top().second < nums[i]) {
                return true;
            } else {
                s.push({nums[i],currmin});
                currmin = min(currmin,nums[i]);
            }
        }
        return false;
    }
};