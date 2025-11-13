class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m , vector<int>(n,0));
        vector<vector<int>> reach(m, vector<int>(n,0));

        int buildings = 0;
        for(int r = 0; r < m ; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == 1) ++ buildings;
            }
        }

        const int dr[4] = {1,-1,0,0};
        const int dc[4] = {0,0,1,-1};

        for(int r0 = 0; r0 < m; r0++) {
            for(int c0 = 0; c0 < n; c0++) {
                if(grid[r0][c0] != 1) continue;
                queue<pair<int, int>> q;
                vector<vector<bool>> vis(m, vector<bool>(n, false));
                q.emplace(r0, c0);
                vis[r0][c0] = true;
                int d = 0;
                while(!q.empty()){
                    int sz = q.size();
                    while(sz--) {
                        auto[r, c] = q.front();
                        q.pop();
                        if(d > 0 && grid[r][c] == 0) {
                            dist[r][c] += d;
                            reach[r][c] += 1;
                        }

                        for (int k = 0; k < 4; ++k) {
                            int nr = r + dr[k], nc = c + dc[k];
                            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                            if (vis[nr][nc]) continue;
                            if (grid[nr][nc] == 2 || grid[nr][nc] == 1) continue; // obstacles/buildings block
                            vis[nr][nc] = true;
                            q.emplace(nr, nc);
                        }
                    }
                    d++;
                }

            }
        }
        int ans = INT_MAX;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (grid[r][c] == 0 && reach[r][c] == buildings)
                    ans = min(ans, dist[r][c]);

        return ans == INT_MAX ? -1 : ans;
    }
};