class Solution {
public:
    unordered_set<int> seen;
    vector<vector<int>> rooms;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        this->rooms = rooms;
        seen.insert(0);
        dfs(0);
        return seen.size() == rooms.size();
    }

    void dfs (int node) {
        for(auto n : rooms[node]) {
            if(!seen.contains(n)) {
                seen.insert(n);
                dfs(n);
            }
        }
    }
};