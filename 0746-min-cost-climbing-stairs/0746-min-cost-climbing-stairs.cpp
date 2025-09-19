class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int i_pls1 = 0;
        int i_pl2 = 0;
        int curr = 0;
        int tmp = 0;

        for(int i = n - 1; i >= 0; i--) {
            curr = cost[i] + min(i_pls1, i_pl2);
            tmp = curr;
            i_pl2 = i_pls1;
            i_pls1 = tmp;
            
        }

        return  min(i_pl2, i_pls1);
       
    }
};