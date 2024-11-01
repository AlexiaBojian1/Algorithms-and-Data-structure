class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i = 0;
        int j = n - 1;

        while (i < j && s[i] == s[j]) {
            char currentChar = s[i];
            // Move i to the right past all characters equal to s[i]
            while (i <= j && s[i] == currentChar) {
                i++;
            }
            // Move j to the left past all characters equal to s[j]
            while (i <= j && s[j] == currentChar) {
                j--;
            }
        }
        // Return the remaining length
        return j - i + 1;
    }
};