class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> all;
        int total = 1 << k;
        for(int i = 0; i + k <= s.length();i++) {
            all.insert(s.substr(i,k));
            if(all.size() == total) {
                return true;
            }
        }
        return false;
    }
};