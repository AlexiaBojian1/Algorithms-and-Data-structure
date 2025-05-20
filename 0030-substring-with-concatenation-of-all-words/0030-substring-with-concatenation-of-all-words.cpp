class Solution {
public:
    int n;
    int k;
    int wordLength;
    unordered_map<string, int> wordCount;
    int substringSize;
    void slidingWindow( int left, string &s, vector<int> &answer) {
        bool excessWord = false;
        unordered_map<string, int> wordFound;
        int wordUsed = 0;
        for(int right = left ; right <= n - wordLength; right += wordLength) {
            string sub = s.substr(right, wordLength);
            if(!wordCount.count(sub)) {
                wordFound.clear();
                excessWord = false;
                wordUsed = 0;
                left = right + wordLength;
            } else {
                while(right - left == substringSize || excessWord) {
                    string leftMost = s.substr(left, wordLength);
                    left += wordLength;
                    wordFound[leftMost] --;
                    if(wordFound[leftMost] >= wordCount[leftMost]) {
                        excessWord = false;
                    } else {
                        wordUsed --;
                    }
                }

                wordFound[sub]++;
                if(wordFound[sub] > wordCount[sub]) {
                    excessWord = true;
                } else {
                    wordUsed ++;
                }
                if(wordUsed == k && !excessWord ) {
                    answer.push_back(left);
                }
            }
        }
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        n = s.length();
        wordLength = words[0].size();
        k = words.size();
        substringSize = wordLength * k;
        for(string &word : words) {
            wordCount[word]++;
        }

        vector<int> answer;
        for(int i = 0; i < wordLength ; i++) {
            slidingWindow(i , s, answer);
        }
        return answer;
    }
};