class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> seen(sentence.begin(), sentence.end());
        return seen.size() == 26;
    }
};