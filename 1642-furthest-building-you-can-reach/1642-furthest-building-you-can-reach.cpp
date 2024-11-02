class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
         // Min-heap to track the smallest climbs we've used ladders for
        priority_queue<int, vector<int>, greater<int>> ladderAllocations;

        for (int i = 0; i < heights.size() - 1; i++) {
            int climb = heights[i + 1] - heights[i];

            // If the next building is lower or the same height, no resources needed
            if (climb <= 0) {
                continue;
            }

            // Use a ladder for this climb by adding the climb size to the heap
            ladderAllocations.push(climb);

            // If we exceed the number of ladders available, replace the smallest ladder allocation with bricks
            if (ladderAllocations.size() > ladders) {
                bricks -= ladderAllocations.top(); // Use bricks for the smallest ladder-used climb
                ladderAllocations.pop(); // Remove this climb from ladder allocations

                // If bricks go negative, return the last reachable building index
                if (bricks < 0) {
                    return i;
                }
            }
        }

        // If we reach here, we can cover all climbs to the last building
        return heights.size() - 1;
    }
};