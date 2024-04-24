class Solution {
public:
    bool isSubsequence(string s, string t) {
        int leftbound = s.size();
        int rightbound = t.size();
        int pleft = 0;
        int pright = 0;
        int count = 0;
        while(pleft < leftbound && pright < rightbound) {
            if(s[pleft] == t[pright]) {
                pleft++;
                pright++;
                count++;
            } else if(s[pleft] != t[pright]) {
                pright++;
            }

        }
        return count == leftbound;
    }
};