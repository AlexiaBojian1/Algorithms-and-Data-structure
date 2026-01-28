class Solution {
public:
    vector<vector<char>> board;
    vector<vector<bool>> seen;
    int m;
    int n;
    vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    void solve(vector<vector<char>>& board) {
        this->board = board;
        n = board.size();
        if(n == 0) return;
        m = board[0].size();
        seen = vector<vector<bool>>(n, vector<bool>(m , false));
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O' && !seen[i][0]) dfs(i, 0);
            if(board[i][m - 1] == 'O' && !seen[i][m - 1]) dfs(i, m - 1);
        }
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O' && !seen[0][j]) dfs(0, j);
            if(board[n - 1][j] == 'O' && !seen[n - 1][j]) dfs(n - 1, j);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!seen[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int x, int y) {
        seen[x][y] = true;
        for(auto direction: directions ) {
            int newx =  x + direction.first;
            int newy = y + direction.second;
            if(valid(newx, newy)) {
                seen[newx][newy] = true;
                dfs(newx, newy);
            }
        }
    }

    bool valid(int x, int y) {
        return x >=0 && y >= 0 && x < n && y < m && board[x][y] == 'O' && !seen[x][y];
    }
};