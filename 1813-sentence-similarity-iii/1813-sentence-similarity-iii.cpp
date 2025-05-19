class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1);
        stringstream ss2(sentence2);
        string word;
        vector<string> s1Word, s2Word;
        while(ss1 >> word) s1Word.push_back(word);
        while(ss2 >> word) s2Word.push_back(word);

        int start = 0;
        int end1 = s1Word.size() - 1;
        int end2 = s2Word.size() - 1;

        if(s1Word.size() > s2Word.size()) return areSentencesSimilar(sentence2 , sentence1);

        while(start < s1Word.size()  && s1Word[start] == s2Word[start]) {
            start++;
        }

        while(end1 >= 0 && s1Word[end1] == s2Word[end2]) {
            end1--;
            end2--;
        }

        return end1 < start;

    }
};