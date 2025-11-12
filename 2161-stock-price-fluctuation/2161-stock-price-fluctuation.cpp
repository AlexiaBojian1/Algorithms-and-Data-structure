class StockPrice {
    int latestTime = 0;
    unordered_map<int, int> timestampMap;
    priority_queue<pair<int, int>> maxheap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minheap;
public:
    StockPrice() {
        latestTime = 0;
    }
    
    void update(int timestamp, int price) {
        latestTime = max(latestTime, timestamp);
        timestampMap[timestamp] = price;
        minheap.push({price, timestamp});
        maxheap.push({price, timestamp});
    }
    
    int current() {
        return timestampMap[latestTime];
    }
    
    int maximum() {
        pair<int, int> top = maxheap.top();
        while(timestampMap[top.second] != top.first) {
            maxheap.pop();
            top = maxheap.top();
        }
        return top.first;
    }
    
    int minimum() {
        pair<int, int> top = minheap.top();
        while(timestampMap[top.second] != top.first) {
            minheap.pop();
            top = minheap.top();
        }
        return top.first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */