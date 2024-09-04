class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = int(graph.size()) - 1;
        vector<int> path = {0};  // Start the path with node 0 (the source node)
        vector<vector<int>> result;
        backtrack(0, path, result, target, graph);
        return result;
    }
    
    void backtrack(int currnode, vector<int>& path, vector<vector<int>>& result, int target, vector<vector<int>>& graph) {
        // If the current node is the target, we've found a valid path
        if(currnode == target) {
            result.push_back(path);  // Copy the current path to the result
            return;
        }

        // Explore all next nodes connected to the current node
        for(int nextnode : graph[currnode]) {
            path.push_back(nextnode);            // Add the next node to the current path
            backtrack(nextnode, path, result, target, graph); // Recurse with the next node
            path.pop_back();                     // Backtrack by removing the last node
        }
    }
};
