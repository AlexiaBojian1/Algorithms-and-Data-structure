class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc , int color ,int initialColor) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != initialColor) {
            return;
        }
        image[sr][sc] = color;
        dfs(image, sr + 1, sc, color, initialColor);
        dfs(image, sr - 1, sc, color, initialColor);
        dfs(image, sr , sc + 1, color, initialColor);
        dfs(image, sr , sc - 1, color, initialColor);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if (initialColor != color)  {
            dfs(image, sr, sc, color , initialColor);
        }
        return image;
    }
};