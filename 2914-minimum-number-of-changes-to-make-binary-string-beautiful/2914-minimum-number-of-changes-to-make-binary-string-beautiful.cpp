class Solution {
public:
    int minChanges(string s) {
        int k = 0;
        for(int i = 0;i < s.length();i= i+2) {
            if(s[i] != s[i+1]) {
                k++;
            }
        } 
        return k;
    }
};