class Solution {
public:
    int m,n;
    vector<vector<char>> board;
    vector<vector<bool>> seen;
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    void solve(vector<vector<char>>& board) {
       this->board = board;
        m = board.size();
        if (m == 0) return;
        n = board[0].size();
        seen = vector<vector<bool>>(m, vector<bool>(n, false));
        
        // Mark 'O's on the boundary and run DFS from there
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !seen[i][0]) dfs(i, 0);
            if (board[i][n-1] == 'O' && !seen[i][n-1]) dfs(i, n-1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !seen[0][j]) dfs(0, j);
            if (board[m-1][j] == 'O' && !seen[m-1][j]) dfs(m-1, j);
        }
        
        // Flip unmarked 'O's to 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!seen[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    void dfs(int row, int col) {
        seen[row][col] = true;
        for (vector<int> direction : directions) {
            int nextrow = row + direction[0];
            int nextcol = col + direction[1];
            if (valid(nextrow, nextcol) && !seen[nextrow][nextcol] && board[nextrow][nextcol] == 'O') {
                dfs(nextrow, nextcol);
            }
        }
    }
    
    bool valid(int row, int col) {
        return 0 <= row && row < m && 0 <= col && col < n;
    }
};