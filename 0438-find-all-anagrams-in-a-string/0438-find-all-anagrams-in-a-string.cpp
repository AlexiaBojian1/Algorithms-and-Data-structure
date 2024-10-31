class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int np = p.length();
        int ns = s.length();

        if(ns < np) return {};

        std::vector<int> pCount(26, 0), sCount(26, 0);
        vector<int> output;
        for(char ch : p) {
            pCount[ch - 'a']++;
        }

        for(int i = 0;i < ns; i++) {
            sCount[s[i] - 'a']++;

            if(i >= np) {
                sCount[s[i - np] - 'a']--;
            }

            if(pCount == sCount) {
                output.push_back(i-np+1);
            }
        }

        return output;
    }
};