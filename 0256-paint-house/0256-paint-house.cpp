class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) return 0;

        int r = costs[0][0];
        int g = costs[0][1];
        int b = costs[0][2];

        for(int i = 1; i < n; i++) {
            int nr = min(g, b) + costs[i][0];
            int ng = min(r, b) + costs[i][1];
            int nb = min(g, r) + costs[i][2];
            r = nr; g = ng; b = nb;
        }

        return min(r, min(g, b));
    }
};