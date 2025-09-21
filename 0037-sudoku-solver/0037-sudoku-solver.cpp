class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }

private:

    bool backtrack(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(isValid(board,  row,  col,  ch)) {
                            board[row][col] = ch;
                            if(backtrack(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == ch) return false;
            if(board[i][col] == ch) return false;

            int bowRow = 3 * (row / 3) + i / 3;
            int bowCol = 3 * (col / 3) + i % 3;
            if(board[bowRow][bowCol] == ch) return false;
        }
        return true;
    }    
};