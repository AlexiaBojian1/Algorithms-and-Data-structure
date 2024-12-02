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
            auto [count_first , char_first] = maxHeap.top();
            maxHeap.pop();
            if(ans.length() >= 2 && ans[ans.length() - 1] == char_first && ans[ans.length() - 2] == char_first) {
                if(maxHeap.empty()) break;

                auto [count_second, char_second] = maxHeap.top();
                maxHeap.pop();
                ans += char_second;
                if(count_second - 1 > 0) {
                    maxHeap.push({count_second - 1, char_second});
                }
            } else {
                count_first--;
                ans += char_first;
            }
            if(count_first > 0) {
                maxHeap.push({count_first, char_first});
            }
        }
        return ans;
    }
};