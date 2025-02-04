class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs[0].empty()) return "";

        for(int i = 0; i<strs[0].size();i++) {
            char c = strs[0][i];
            for(int j = 1; j< strs.size(); j++) {
                if(strs[j].size() == i || strs[j][i] != c) {
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};