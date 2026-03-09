class Solution {
public:
    vector<vector<bool>> seen;
    vector<vector<char>> board;
    int m, n;
    string word;
    vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0},{0, -1}};
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        n = board.size();
        m = board[0].size();
        vector<int> freqBoard(128, 0), freqWord(128, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                freqBoard[board[i][j]]++;
            }
        }
        for (char c : word) {
            freqWord[c]++;
        }
        for (int c = 0; c < 128; c++) {
            if (freqWord[c] > freqBoard[c]) return false;
        }
        seen = vector<vector<bool>>(n , vector(m , false));
        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < m; j++) {
                if(board[i][j] == word[0]) {
                    seen[i][j] = true;
                    if(dfs(i, j, 1)) return true;
                    seen[i][j] = false;         
                }
            }
        }
        return false;
    }

    bool dfs(int x, int y, int nextletter) {
        if(nextletter == word.length()) return true;
        for(auto dir : directions) {
            int newx = dir[0] + x;
            int newy = dir[1] + y;
            if(valid(newx, newy) && board[newx][newy] == word[nextletter]) {
                seen[newx][newy] = true;
                if (dfs(newx, newy, nextletter + 1)) return true;
                seen[newx][newy] = false;
            } 
        }
        return false;
    }

    bool valid(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m && !seen[x][y];
    }
};