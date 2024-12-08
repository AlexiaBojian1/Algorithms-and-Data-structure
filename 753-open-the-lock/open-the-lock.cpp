class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(find(deadends.begin(), deadends.end(), "0000") != deadends.end()) {
            return -1;
        }

        queue<pair<string, int>> queue;
        queue.push(pair("0000",0));
        unordered_set<string> seen (deadends.begin(), deadends.end());

        while(!queue.empty()) {
            auto [node, step] = queue.front();
            queue.pop();
            if(node == target) {
                return step;
            }

            for(string n : neighbor(node)) {
                if(seen.find(n) == seen.end()) {
                    seen.insert(n);
                    queue.push(pair(n, step+1));
                }
            }
        }
        return -1;
    }

    vector<string> neighbor(string node) {
        vector<string> ans;
        for(int i = 0; i < 4;i++) {
            char num = node[i];
            for(int change : {-1,1}) {
                int x = (num - '0' + change + 10) %10 + '0';
                string neighbor = node;
                neighbor[i] = x;
                ans.push_back(neighbor);
            }
        }
        return ans;
    }
};