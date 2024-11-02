class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto& [ch, count] : freq) {
            pq.push({count, ch});
        }

        string ans = "";

        while (!pq.empty()) {
            auto [count_first, char_first] = pq.top();
            pq.pop();

            if (ans.empty() || ans.back() != char_first) {
                ans += char_first;
                count_first--;

                if (count_first > 0) {
                    pq.push({count_first, char_first});
                }
            } else {
                if (pq.empty()) {
                    return "";
                }

                auto [count_second, char_second] = pq.top();
                pq.pop();

                ans += char_second;
                count_second--;
                
                if (count_second > 0) {
                    pq.push({count_second, char_second});
                }
                pq.push({count_first, char_first});
            }
        }
        return ans;
    }
};
