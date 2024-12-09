class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> queue;
        unordered_set<string> seen;
        queue.push(pair(startGene, 0));
        seen.insert(startGene);
        while(!queue.empty()) {
            auto[node, step] = queue.front();
            queue.pop();
            if(node == endGene) {
                return step;
            }
            
            for(char c : "ACGT") {
                for(int i = 0; i < node.size();i++) {
                    string neighbour = node;
                    neighbour[i] = c;
                    if(!seen.count(neighbour) && find(bank.begin(), bank.end(), neighbour) != bank.end()) {
                        queue.push(pair(neighbour, step+1));
                        seen.insert(neighbour);
                    }
                }
            }
        }
        return -1;
    }
};