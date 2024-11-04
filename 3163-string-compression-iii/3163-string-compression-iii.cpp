class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int pos = 0;
        while (pos < word.length()) {
            char c = word[pos];
            int consecutiveCount = 0;
            while(pos < word.length() && consecutiveCount < 9 && word[pos] == c) {
                pos++;
                consecutiveCount ++;
            }
            comp += to_string(consecutiveCount) + c;
        }
        return comp;
    }
};