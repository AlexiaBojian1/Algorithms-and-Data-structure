class Solution {
public:
    unordered_map<int, vector<int>> graph;
    set<vector<int>> roads;
    vector<bool> seen;
    int minReorder(int n, vector<vector<int>>& connections) {
        for(auto connection : connections) {
            int from = connection[0];
            int to = connection[1];
            graph[from].push_back(to);
            graph[to].push_back(from);
            roads.insert(connection);
        }
        seen = vector(n, false);
        int ans = 0;
        seen[0] = true;
        ans = dfs(0);
        return ans;
    }

    int dfs(int node) {
        int ans = 0;
        for(auto n : graph[node]) {
            if(!seen[n]) {
                seen[n] = true;
                if(roads.contains({node, n})) ans++;
                ans += dfs(n);
            }
        }
        return ans;
    }
};