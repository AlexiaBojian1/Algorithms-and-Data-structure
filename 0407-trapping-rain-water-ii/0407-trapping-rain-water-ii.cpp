class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;
        

        vector<vector<bool>> vis(m, vector<bool>(n , false));
        using Cell = tuple<int, int, int>; //h, r, c
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

        for(int r = 0; r < m; r++) {
            pq.emplace(heightMap[r][0], r, 0);
            pq.emplace(heightMap[r][n - 1], r, n - 1);
            vis[r][0] = true;
            vis[r][n - 1] = true;
        }

        for(int c = 0; c < n; c++) {
            if(!vis[0][c]) {
                pq.emplace(heightMap[0][c], 0, c);
                vis[0][c] = true;
            }
            if(!vis[m - 1][c]) {
                pq.emplace(heightMap[m - 1][c], m - 1, c);
                vis[m - 1][c] = true;
            }
        }

        long long water = 0;
        int level = 0;
        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while(!pq.empty()) {
            auto [h, r, c] = pq.top();
            pq.pop();
            level = max(level, h);

            for(auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr < 0 || nr >= m || nc < 0 || nc >= n || vis[nr][nc]) continue;
                vis[nr][nc] = true;

                int nh = heightMap[nr][nc];
                if(nh < level) {
                    water += (level - nh);
                }
                pq.emplace(max(nh, level), nr, nc);
            }
        }

        return water;
    }
};