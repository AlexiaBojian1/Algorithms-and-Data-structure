class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(); // rows
        int n = boxGrid[0].size(); // columns
        vector<vector<char>> result(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][i] = boxGrid[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            reverse(result[i].begin(), result[i].end());
        }

         for (int j = 0; j < m; j++) {
            int lowestRowWithEmptyCell = n - 1;
            // Process each cell in column `j` from bottom to top
            for (int i = n - 1; i >= 0; i--) {
                // Found a stone - let it fall to the lowest empty cell
                if (result[i][j] == '#') {
                    result[i][j] = '.';
                    result[lowestRowWithEmptyCell][j] = '#';
                    lowestRowWithEmptyCell--;
                }
                // Found an obstacle - reset `lowestRowWithEmptyCell` to the row
                // directly above it
                if (result[i][j] == '*') {
                    lowestRowWithEmptyCell = i - 1;
                }
            }
        }
        return result;
    }
};