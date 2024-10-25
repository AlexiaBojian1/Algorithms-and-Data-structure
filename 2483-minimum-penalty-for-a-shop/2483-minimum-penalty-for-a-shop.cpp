class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int pen = 0;
        int res = -1;
        int maxi  = -1;
        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') {
                pen++;
            } else{
                pen--;
            }
            if(pen > maxi) {
                maxi = pen;
                res = i;
            }
        }
        return ++res;
    }
};