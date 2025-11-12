class Solution {
public:
     vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();        // number of rows
        int m = A[0].size();     // number of columns

        for (auto& row : A) {    // iterate over each row (by reference so we modify it directly)
            for (int i = 0; i < (m + 1) / 2; ++i) {
                int tmp = row[i] ^ 1;
                row[i] = row[m - 1 - i] ^ 1;
                row[m - 1 - i] = tmp;
            }
        }
        return A;
    }

};