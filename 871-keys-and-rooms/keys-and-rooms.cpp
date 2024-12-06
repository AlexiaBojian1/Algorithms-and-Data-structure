class Solution {
public:
    vector<vector<int>> rooms;
    unordered_set<int> seen;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        this->rooms = rooms;
        int n = rooms.size();
        seen.insert(0);
        dfs(0);
        return rooms.size() == seen.size();
    }

    void dfs(int room) {
        for (int nid : rooms[room]) {
            if (seen.find(nid) == seen.end()) {
                seen.insert(nid);
                dfs(nid);
            }
        }
    }
};