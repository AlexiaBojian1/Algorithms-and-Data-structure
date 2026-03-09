class Solution {
public:
    string alienOrder(vector<string>& words) {
      unordered_map<char, unordered_set<char>> graph;
      unordered_map<char, int> degree;

      for(auto word : words) {
        for(auto c: word) {
            graph[c];
            degree[c] = 0;
        }
      }

      for(int i =0; i < words.size() - 1; i++) {
        string& w1 = words[i];
        string& w2 = words[i + 1];
        bool foundiff = false;
        int minlen = min(w1.size(), w2.size());
        for(int j = 0; j < minlen; j++) {
            char c1 = w1[j];
            char c2 = w2[j];
            if(c1 != c2) {
                if(!graph[c1].count(c2)) {
                    graph[c1].insert(c2);
                    degree[c2]++;
                }
                foundiff = true;
                break;
            }
        }
        if (!foundiff && w1.size() > w2.size()) return "";
      }  
      queue<char> q;
      for(auto [c, deg] : degree) {
        if(deg == 0) q.push(c);
      }
      
      string result;
      while(!q.empty()) {
        char current = q.front();
        q.pop();
        result += current;
        for(auto nei : graph[current]) {
            degree[nei]--;
            if(degree[nei] == 0) {
                q.push(nei);
            }
        }
      }
      return result.size() == graph.size() ? result : "";
    }
};