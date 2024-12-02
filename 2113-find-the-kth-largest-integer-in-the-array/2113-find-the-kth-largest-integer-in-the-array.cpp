class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto comp = [](const string& a, const string& b) {
            if (a.size() == b.size()) {
                return a > b; // lexicographical comparison if same length
            }
            return a.size() > b.size(); // compare by length
        };
        
        priority_queue<string, vector<string>, decltype(comp)> minHeap(comp);

        for (const string& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};