class Solution {
public:
    bool validPalindrome(string s) {
     auto isPalindrome = [&](int left, int right) {
            while (left < right) {
                if (s[left] != s[right])
                    return false;
                left++;
                right--;
            }
            return true;
        };

        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                // Check two possible scenarios - removing one character
                return isPalindrome(left + 1, right) || isPalindrome(left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }

};