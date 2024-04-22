class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0) {
        return false; // Negative numbers are not palindromes
    }
    
    std::string s = std::to_string(x);
    int len = s.length();
    for (int i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - i - 1]) {
            return false;
        }
    }
    return true;
    }
};