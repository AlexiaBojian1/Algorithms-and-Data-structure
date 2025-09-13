class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int t1 = INT_MAX;
        int t2 = INT_MAX;
        int t1_profit = 0;
        int t2_profit = 0;

        for(int price : prices) {
            t1 = min(t1, price);
            t1_profit = max(price - t1, t1_profit);
            t2 = min(t2, price - t1_profit);
            t2_profit = max(t2_profit, price - t2);
        }
        return t2_profit;
    }
};