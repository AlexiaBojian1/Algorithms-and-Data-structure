class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice  = INT_MAX;
        int maxPrice = 0;
        for(auto price : prices) {
            if(price < minPrice) {
                minPrice = price;
            }
            if(price - minPrice > maxPrice) {
                maxPrice = price - minPrice;
            }
        }
        return maxPrice;
    }
};