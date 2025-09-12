class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int np = p.length();
        int ns = s.length();
        vector <int> result;

        if(ns < np) return {};

        vector<int> pcount(26, 0), scount(26, 0);

        for(char ch : p) {
            pcount[ch - 'a']++;
        }

        for(int i = 0; i < ns; i++) {

            scount[s[i] - 'a']++;

            if(i >= np) {
                scount[s[i - np] - 'a']--;
            } 

            if(pcount == scount) {
                result.push_back(i - np + 1);
            }
        }
        return result;
    }
};