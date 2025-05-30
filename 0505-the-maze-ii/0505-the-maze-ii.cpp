class Solution {
public:
    vector<vector<int>> maze;
    vector<vector<int>>  directions=  {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int n;
    int m;
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        this->maze = maze;
        this-> m = maze[0].size();
        this-> n = maze.size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[start[0]][start[1]] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, start[0], start[1]});

        while(!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int d = curr[0], r = curr[1], c = curr[2];

            // Skip if we have already found a better path
            if (d > dist[r][c]) continue;

             for (auto direction : directions) {
                int row = r, col = c, steps = 0;

                // Roll the ball until it hits a wall
                while (valid(row + direction[0], col + direction[1])) {
                    row += direction[0];
                    col += direction[1];
                    steps++;
                }

                if (dist[r][c] + steps < dist[row][col]) {
                    dist[row][col] = dist[r][c] + steps;
                    pq.push({dist[row][col], row, col});
                }
            }
        }

        int result = dist[destination[0]][destination[1]];
        return result == INT_MAX ? -1 : result;
    }
    bool valid(int row, int col) {
        return row >= 0 && row < n && col >= 0 && col < m && maze[row][col] == 0;
    }
};