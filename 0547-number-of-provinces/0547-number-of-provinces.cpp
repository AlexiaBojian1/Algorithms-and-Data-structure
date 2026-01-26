class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        seen = vector(n, false);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < m; j++) {
                if(isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!seen[i]) {
                ans ++;
                seen[i] = true;
                dfs(i);
            }
        }
        return ans;
    }

    void dfs(int node) {
        for(auto neightbours : graph[node]) {
            if(!seen[neightbours]) {
                seen[neightbours] = true;
                dfs(neightbours);
            }
        }
    }
};