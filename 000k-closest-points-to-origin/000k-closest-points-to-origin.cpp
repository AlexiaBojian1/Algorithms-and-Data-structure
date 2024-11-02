class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> maxheap;
        for(int i = 0; i < points.size() ;i++) {
            pair<int,int> entry = {squaredDistance(points[i]),i};
            maxheap.push(entry);
            if(maxheap.size() > k) {
                maxheap.pop();
            }
        }
        
        vector<vector<int>> answer;
        while (!maxheap.empty()) {
            int entryIndex = maxheap.top().second;
            maxheap.pop();
            answer.push_back(points[entryIndex]);
        }
        return answer;
        
    }
    
private:
    int squaredDistance(vector<int>& point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }    
};