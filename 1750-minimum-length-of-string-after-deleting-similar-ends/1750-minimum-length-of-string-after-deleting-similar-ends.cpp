class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i = 0;
        int j = n - 1;

        while(i < j && s[i] == s[j]) {
            char curr = s[i];
            while(i <= j && curr == s[i]) {
                i++;
            }

            while(i <= j && curr == s[j]){
                j--;
            }
        }
        return j - i + 1;
    }
};