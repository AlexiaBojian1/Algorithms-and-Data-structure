class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;

        while( ss >> word) {
            words.push_back(word);
        }

        for(int i = 0 ;i < words.size(); i++) {
            int nextindex = (i+1)% words.size();
            if (words[i].back() != words[nextindex].front()) {
                return false;
            }
        }
        return true;
    }
};