class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        queue<pair<string, int>> queue;
        queue.push(pair(beginWord,1));
        
        while(!queue.empty()) {
            auto[node, step] = queue.front();
            queue.pop();
            
            if(node == endWord) {
                return step;
            }
            
            for(int i = 0; i < node.size(); i++) {
                char originalchar = node[i];
                for(char c = 'a' ; c<= 'z'; c++) {
                    if(c == originalchar) continue;
                    node[i] = c;
                    if(wordSet.find(node) != wordSet.end()) {
                        queue.push(pair(node, step + 1));
                        wordSet.erase(node);
                    }
                }
                node[i] = originalchar;
            }
        }
        return 0;
    }
};