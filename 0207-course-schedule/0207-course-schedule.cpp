class Solution {
public:
    vector<int> state;
    unordered_map<int, vector<int>> graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto courses : prerequisites) {
            graph[courses[1]].push_back(courses[0]);
        }

        state = vector<int>(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i)) return false;
        }

        return true;
    }

    bool dfs(int node) {
        if(state[node] == 1) return false;
        if(state[node] == 2) return true;

        state[node] = 1;

        for(int nei : graph[node]) {
            if(!dfs(nei)) return false;
        }

        state[node] = 2;
        return true;
    }
};