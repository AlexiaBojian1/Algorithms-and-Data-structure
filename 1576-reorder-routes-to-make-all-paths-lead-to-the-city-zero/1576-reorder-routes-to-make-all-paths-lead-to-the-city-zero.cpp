class Solution {
public:
    set<vector<int>> roads;
    vector<bool> seen;
    unordered_map<int, vector<int>> graph;
    int minReorder(int n, vector<vector<int>>& connections) {
        seen = vector(n, false);
        for(int i = 0;i < connections.size(); i++) {
            int x = connections[i][0];
            int y = connections[i][1];
            graph[x].push_back(y);
            graph[y].push_back(x);
            roads.insert({x,y});
        }
        seen[0] = true;
        return dfs(0);
    }

    int dfs(int i) {
        int ans = 0;
        for(int neight : graph[i]) {
            if(!seen[neight]) {
                if(roads.find({i,neight}) != roads.end()) {
                    ans++;
                }
                seen[neight] = true;
                ans += dfs(neight);
            }
        }
        return ans;
    }
};