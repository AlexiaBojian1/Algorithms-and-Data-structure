class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char,int> inDegree;

        for(const string& word: words) {
            for (char c : word) {
                graph[c];
                inDegree[c] = 0;
            }
        }

        for(int i = 0; i < words.size() - 1; i++) {
            string& w1 = words[i];
            string& w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());
            bool foundDiff = false;

            for(int j = 0; j < minLen; j++) {
                char c1 = w1[j];
                char c2 = w2[j];
                if(c1 != c2) {
                    if(!graph[c1].count(c2)) {
                        graph[c1].insert(c2);
                        inDegree[c2]++;
                    }
                    foundDiff = true;
                    break;
                }
            }
            if (!foundDiff && w1.size() > w2.size()) return "";
        }

        queue<char> q;
        for(auto& [c, deg] : inDegree) {
            if(deg == 0) q.push(c);
        }

        string result;
        while(!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;
            for(char neighbor : graph[curr]) {
                if(--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        if(result.size() != graph.size()) return "";
        return result;
    }
};