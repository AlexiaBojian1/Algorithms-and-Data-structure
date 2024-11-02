class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap (piles.begin(), piles.end());
        int target  = 0;
        for (int pile : piles) {
            target += pile;
        }
        
        while(k) {
            int current = heap.top();
            heap.pop();
            int stonesToRemove = current / 2;
            target -= stonesToRemove;
            heap.push(current  - stonesToRemove);
            k--;
        }
        return target;
    }
};