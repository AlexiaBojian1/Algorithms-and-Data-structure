class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;
        if(a > 0) {
            maxHeap.push({a,'a'});
        }
        if(b > 0) {
            maxHeap.push({b,'b'});
        }
        if(c > 0) {
            maxHeap.push({c,'c'});
        }
    
        string ans = "";
        while(!maxHeap.empty()) {
            auto [count, element] = maxHeap.top();
            maxHeap.pop();
            if(ans.length() >= 2 && ans[ans.length() - 1] == element && ans[ans.length() - 2] == element) {
                if(maxHeap.empty()) break;
                auto[counttemp , elemtemp] = maxHeap.top();
                maxHeap.pop();
                ans += elemtemp;
                if(counttemp - 1 > 0) {
                    maxHeap.push({counttemp - 1, elemtemp});
                }
            }
            else {
                ans += element;
                count--;
            }
            if(count> 0) {
                maxHeap.push({count, element});
            }
        }
        return ans;
    }
};