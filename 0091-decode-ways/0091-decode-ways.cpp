class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int pprev = 1;
        int prev = (s[0] == '0') ? 0 : 1;
        int current = 0;
        for(int i = 2; i <= n; i++) {
            current = 0;
            int onedigit = stoi(s.substr(i - 1, 1));
            if(onedigit >= 1 && onedigit <= 9) {
                current += prev;
            }

            int twodigit = stoi(s.substr(i - 2, 2));
            if(twodigit >= 10 && twodigit <= 26) {
                current += pprev;
            }
            pprev = prev;
            prev = current;
        }
        return prev;
    }
};