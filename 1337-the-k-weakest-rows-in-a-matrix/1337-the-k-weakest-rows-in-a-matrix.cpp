class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    // Define a max heap to keep track of the weakest rows
    priority_queue<pair<int, int>> maxHeap;
    
    for (int i = 0; i < mat.size(); i++) {
        // Count the number of soldiers in the current row
        int soldierCount = 0;
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 1) soldierCount++;
            else break;
        }
        
        // Push the soldier count and index into the max heap
        maxHeap.push({soldierCount, i});
        
        // Ensure the heap size does not exceed k
        if (maxHeap.size() > k) {
            maxHeap.pop();  // Remove the strongest row in the heap
        }
    }

    // Extract the weakest k rows from the heap into a result vector
    vector<int> result(k);
    while (!maxHeap.empty()) {
        result[--k] = maxHeap.top().second;
        maxHeap.pop();
    }

    return result;
    }
};