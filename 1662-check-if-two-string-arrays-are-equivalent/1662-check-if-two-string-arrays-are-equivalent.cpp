class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        std::string str1, str2;

        // Concatenate all strings in word1
        for(const std::string &s : word1) {
            str1 += s;
        }

        // Concatenate all strings in word2
        for(const std::string &s : word2) {
            str2 += s;
        }

        // Compare the concatenated strings
        return str1 == str2;
    }
};