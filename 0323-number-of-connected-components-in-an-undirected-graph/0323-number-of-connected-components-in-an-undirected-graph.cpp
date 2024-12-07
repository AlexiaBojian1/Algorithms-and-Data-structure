class Solution {
public:
    unordered_map<int,vector<int>> graph;
    vector<bool> seen;

    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
         seen = vector(n, false);
        for(auto& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        for(int i=0;i<n;i++) {
            if(!seen[i]) {
                seen[i] = true;
                ans++;
                dfs(i);
            }
        }
        return ans;

    }

    void dfs(int node) {
        for(int neigh : graph[node]) {
            if(!seen[neigh]) {
                seen[neigh] = true;
                dfs(neigh);
            }
        }
    }
};