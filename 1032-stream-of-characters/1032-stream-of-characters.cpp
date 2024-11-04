class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class StreamChecker {
private: 
    TrieNode * trieRoot;
    deque<char> stream;
    int maxWordLength = 0;

public:
    StreamChecker(vector<string>& words) {
        trieRoot = new TrieNode();
        
        // Build the Trie with reversed words
        for (const std::string& word : words) {
            TrieNode* node = trieRoot;
            maxWordLength = std::max(maxWordLength, (int)word.size());
            
            // Insert the word in reversed order
            for (int i = word.size() - 1; i >= 0; --i) {
                char ch = word[i];
                if (node->children.find(ch) == node->children.end()) {
                    node->children[ch] = new TrieNode();
                }
                node = node->children[ch];
            }
            node->isWord = true; // Mark end of a valid word
        }
    }
    
    bool query(char letter) {
        stream.push_front(letter); // Add the character to the front of the deque
    
        // Limit the size of the stream to the longest word in the Trie
        if (stream.size() > maxWordLength) {
            stream.pop_back();
        }
        
        TrieNode* node = trieRoot;
        for (char ch : stream) {
            if (node->isWord) return true; // Found a matching suffix
            if (node->children.find(ch) == node->children.end()) return false;
            node = node->children[ch];
        }
        return node->isWord;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */