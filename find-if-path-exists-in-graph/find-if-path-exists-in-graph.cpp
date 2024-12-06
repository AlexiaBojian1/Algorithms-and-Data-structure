class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;
    int source;
    int destination;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        seen = vector(n, false);
        if (source == destination) {
            return true;
        }
        this->destination = destination;
        this->source = source;
        for(auto edge : edges) {
            int x = edge[0];
            int y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        seen[source] = true;
        return dfs(source, destination);
    }
    
    bool dfs(int s , int d) {
        for(int n : graph[s]) {
            if(n == d) {
                return true;
            } else {
                if(!seen[n]) {
                    seen[n] = true;
                    if (dfs(n, d)) { 
                          return true; 
                      }
                }
            }
        }
        return false;
    }
};