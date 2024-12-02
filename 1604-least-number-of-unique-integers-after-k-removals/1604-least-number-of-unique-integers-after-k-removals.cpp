class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> count;
        for(int num : arr) {
            count[num] ++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> minHeap;
        for(auto entry : count) {
            minHeap.push({entry.second, entry.first});
        }

        while(k > 0 && !minHeap.empty()) {
            auto current = minHeap.top();
            minHeap.pop();
            int freq = current.first;

            if(k >= freq) {
                k -= freq;
            } else {
                minHeap.push({current.first - k, current.second});
                k = 0;
            }
        }
        return minHeap.size();

    }
};