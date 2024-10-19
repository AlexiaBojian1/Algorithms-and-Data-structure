class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = {0};
        int target = graph.size() - 1;
        vector<vector<int>> results;
        backtrack(0, target, graph, path, results);
        return results;
    }

    void backtrack(int curr, int& target, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& results) {
        if(curr == target){
            results.push_back(path);
            return;
        }

        for(int nextnode: graph[curr]) {
            path.push_back(nextnode);
            backtrack(nextnode, target, graph, path, results);
            path.pop_back();
        }
    }
};