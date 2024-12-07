class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;
    int n;
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        this-> n = n;
        unordered_set<int> restrictedSet(restricted.begin(), restricted.end());
        for(auto edge : edges) {
            int x = edge[0];
            int y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        seen = vector(n, false);
        seen[0] = true;
        return dfs(0, restrictedSet);
    }
    
    int dfs(int node, unordered_set<int>& res) {
        int ans = 1;
        for( int n : graph[node]) {
            if(res.find(n) != res.end() || seen[n]) {
                continue;
            } else {
                if(!seen[n]) {
                    seen[n] = true;
                    ans = ans + dfs(n, res);
                }
               
            }
        }
        return ans;
    }
};