class Solution {
private:
    bool isValid(const vector<int>& board, int row, int col) {
        for( int i = 0; i < row; i++) {
            if (board[i] == col || board[i] - i == col - row || board[i] + i == row + col) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<int> board(n , -1);
        backtrack(0, n, board, results);
        return results;
    }

    void backtrack(int row, int n , vector<int>& board, vector<vector<string>> & result) {
        if(row == n) {
            vector<string> solution;
            for(int i = 0; i < n ;i++) {
                string line(n, '.');
                line[board[i]] = 'Q';
                solution.push_back(line);
            }
            result.push_back(solution);
            return;
        }

        for(int col = 0; col < n ;col ++) {
            if(isValid(board, row, col)) {
                board[row] = col;
                backtrack(row+1,n, board, result);
                board[row] = -1;
            }
        }
    }
};