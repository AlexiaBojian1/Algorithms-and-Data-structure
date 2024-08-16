class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    int i1 = 0, i2 = 0; // indices for words in word1 and word2
        int j1 = 0, j2 = 0; // indices for characters within the current word

        while (i1 < word1.size() && i2 < word2.size()) {
            // Compare the current characters
            if (word1[i1][j1] != word2[i2][j2]) {
                return false;
            }

            // Move to the next character in word1
            if (++j1 == word1[i1].length()) {
                j1 = 0;
                i1++;
            }

            // Move to the next character in word2
            if (++j2 == word2[i2].length()) {
                j2 = 0;
                i2++;
            }
        }

        // Both arrays should be fully traversed if they are equal
        return i1 == word1.size() && i2 == word2.size();
    }
};