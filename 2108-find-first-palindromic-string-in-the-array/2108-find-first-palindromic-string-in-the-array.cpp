class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string word : words) {
            string reversed(word.rbegin(), word.rend());
            if ( word == reversed) {
                return word;
            }
        }
        return "";
    }
};