class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> frquency;
        for(char c: s) {
            frquency[c]++;
        }

        vector<pair<char,int>> freq;
        for(auto& entry : frquency) {
            freq.push_back(entry);
        }

        sort(freq.begin(), freq.end(),[](pair<char,int>& a, pair<char,int>& b) {
            return b.second < a.second;
        });

        string result;
        for(auto& entry : freq) {
            result += string(entry.second,entry.first);
        }
        return result;
    }
};