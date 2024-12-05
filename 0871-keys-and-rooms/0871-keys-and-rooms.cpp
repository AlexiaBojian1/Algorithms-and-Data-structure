class Solution {
public:
    vector<vector<int>> rooms;
    unordered_set<int> seen;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        this->rooms = rooms;
        seen.insert(0);
        dfs(0);
        return rooms.size()== seen.size();
    }
    void dfs(int node) {
        for( int nid : rooms[node]) {
            if(seen.find(nid) == seen.end()){
                 seen.insert(nid);
                dfs(nid);
            }
              
            }
        }
};