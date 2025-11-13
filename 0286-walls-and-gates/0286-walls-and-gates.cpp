class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if(m == 0) return;
        int n = rooms[0].size();

        queue<pair<int, int>> q;
        const int INF = 2147483647;
        const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n ; c++) {
                if(rooms[r][c] == 0) {
                    q.emplace(r,c);
                }
            }
        }

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if(rooms[nr][nc] == -1)  continue;

                if (rooms[nr][nc] > rooms[r][c] + 1) {
                    rooms[nr][nc] = rooms[r][c] + 1;
                    q.emplace(nr, nc);
                }    
            }

        }
    }
};