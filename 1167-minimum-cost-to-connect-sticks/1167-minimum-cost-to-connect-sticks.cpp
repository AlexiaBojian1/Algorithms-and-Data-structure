class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> heap (sticks.begin(), sticks.end());
        if(heap.size() == 1) {
            return 0;
        }
        int cost = 0;
        while(heap.size() > 1) {
            int first = heap.top();
            heap.pop();
            int second = heap.top();
            heap.pop();
            cost =  cost + second + first;
            heap.push(second+first);
        }
        return cost;
    }
};