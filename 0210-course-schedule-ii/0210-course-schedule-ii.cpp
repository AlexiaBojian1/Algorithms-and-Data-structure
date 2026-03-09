class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        for(auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            degree[p[0]] ++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(degree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> order;
        order.reserve(numCourses);

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for(auto v : graph[u]) {
                degree[v]--;
                if(degree[v] == 0) q.push(v);
            }
        }
        return order.size() == numCourses ? order : vector<int>{};
    }
};