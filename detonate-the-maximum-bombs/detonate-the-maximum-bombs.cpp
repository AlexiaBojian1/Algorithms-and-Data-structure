class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int>> graph;
        int n = bombs.size();
        for(int i = 0; i <  n;i++) {
            for(int j = 0; j < n;j++) {
                if(i == j) {
                    continue;
                }
                long long xi = bombs[i][0], yi = bombs[i][1], r = bombs[i][2];
                long long xj = bombs[j][0], yj = bombs[j][1];
                if (r * r >= (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj)) {
                    graph[i].push_back(j);
                }
            }
        }
        
        std::function<int(int, unordered_set<int>&)>  dfs = [&](int cur, unordered_set<int>& visited) -> int{
            visited.insert(cur);
            int count = 1;
            for(int neighbor : graph[cur]) {
                if(!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    count += dfs(neighbor, visited);
                }
            }
            return count;
        };
        
        int answer = 0;
        for(int i = 0; i < n;i++) {
            unordered_set<int> visited;
            answer = max(answer, dfs(i, visited));
        }
        return answer;
    }
};