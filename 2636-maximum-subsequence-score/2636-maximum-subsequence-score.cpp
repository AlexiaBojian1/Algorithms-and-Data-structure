class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> pairs(n);
        

        for(int i = 0;i < n ; i++) {
            pairs[i] = {nums1[i], nums2[i]};
        }

        sort(pairs.rbegin(), pairs.rend(), [](pair<int, int>& a, pair<int,int>& b){
            return b.second > a.second;
        });

        priority_queue<int, vector<int> , greater<int>> minHeap;
        long long topKsum = 0;
        for(int i = 0; i < k; i++) {
            topKsum += pairs[i].first;
            minHeap.push(pairs[i].first);
        }

        long long answer = topKsum * pairs[k - 1].second;

        for(int i = k ; i < n ; i++) {
            topKsum += pairs[i].first - minHeap.top();
            minHeap.pop();
            minHeap.push(pairs[i].first);

            answer = max(answer, topKsum * pairs[i].second);
        }
        return answer;
    }
};