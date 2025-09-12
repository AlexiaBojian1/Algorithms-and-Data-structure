class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> queue;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            while(!queue.empty() && nums[queue.back()] < nums[i]) {
                queue.pop_back();
            }

            queue.push_back(i);

            if(queue.front() + k == i) {
                queue.pop_front();
            }

            if(i >= k - 1) {
                ans.push_back(nums[queue.front()]);
            }
        }
        return ans;
    }
};