class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto& row : image) {
            int left = 0;
            int right = row.size() - 1;
            while(left < right) {
                int ans;
                ans = row[left];
                row[left] = row[right];
                row[right] = ans;
                left++;
                right--;
            }
        }

        for(auto& row: image) {
            for(int i = 0; i < row.size(); i++) {
                if(row[i] == 0) {
                    row[i] = 1;
                } else {
                    row[i] = 0;
                }
            }
        }

        return image;
    }

};