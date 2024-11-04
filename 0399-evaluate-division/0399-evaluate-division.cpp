class Solution {
public:

    double dfs(const string & current, const string& target, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited) {
        if(current == target) {
            return 1.0;
        }

        visited.insert(current);
        for(const auto& neighbor : graph[current]) {
            const string& nextNode = neighbor.first;
            const double value = neighbor.second;

            if(visited.count(nextNode) == 0) {
                double result = dfs(nextNode, target, graph, visited);
                if(result != -1.0) {
                    return result * value;
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        //Build the graph
        unordered_map<string, unordered_map<string, double>> graph;

        for(int i = 0; i < equations.size(); i++) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            double value = values[i];

            graph[A][B] = value;
            graph[B][A] = 1.0/value;
        }

        //Process each query
        vector<double> results;
        for(const auto& query : queries) {
            const string & C = query[0];
            const string &D  = query[1];

            if(graph.find(C) == graph.end() || graph.find(D) == graph.end()) {
                results.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                double result = dfs(C,D,graph,visited);
                results.push_back(result);
            }
        }
        return results;

    }
}; 