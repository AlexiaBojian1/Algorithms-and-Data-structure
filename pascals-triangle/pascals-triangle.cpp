class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangles;
        triangles.push_back({1});
        for(int i = 1; i < numRows; i++) {
            vector<int> row;
            vector<int> prevrow = triangles[i-1];
            row.push_back(1);
            for(int j = 1; j < i; j++) {
                row.push_back(prevrow[j-1] + prevrow[j]);
            }
            row.push_back(1);
            triangles.push_back(row);
        }
        return triangles;
    }
};