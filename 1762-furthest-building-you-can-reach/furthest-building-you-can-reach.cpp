class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int> , greater<int>> minHeap;
        for(int i = 0; i < heights.size() - 1; i++) {
            int climb = heights[i + 1] - heights[i];
            if(climb <= 0) {
                continue;
            }
            minHeap.push(climb);
            if(minHeap.size() > ladders) {
                bricks -= minHeap.top();
                minHeap.pop();

                if(bricks < 0) {
                    return i;
                }
            }
           
        }
        return heights.size() - 1;
    }
};