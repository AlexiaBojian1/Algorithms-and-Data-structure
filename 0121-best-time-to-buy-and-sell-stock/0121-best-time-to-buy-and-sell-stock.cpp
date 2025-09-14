class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int maxprofit = 0;
        for(int price : prices) {
            if(price < min) {
                min  = price;
            }
            if(price - min > maxprofit) {
                maxprofit = price - min;
            }
        }
        return maxprofit;
    }
};