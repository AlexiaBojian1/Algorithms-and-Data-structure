class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        if(s.size() == 0) {
            return 0;
        }
        if(g[0] > s[0]) {
            return 0;
        }
        int p1 = 0;
        int p2 = 0;
        int count = 0;
        while(p1 < g.size() && p2 < s.size()) {
            if(p2 < s.size() && s[p2] >= g[p1]) {
                count++;
                p2++;
                p1++;
            } else if(s[p2] < g[p1]) {
                p2++;
            }
        }
        return count;
    }
};