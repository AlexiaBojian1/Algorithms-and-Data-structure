class Solution {
public:
    int partitionString(string s) {
       unordered_set<char> seen;
       int k = 1;
       for(char c : s) {
            if(seen.find(c) != seen.end()) {
                k++;
                seen.clear();
            }
            seen.insert(c);
       }
       return k;
    }
};