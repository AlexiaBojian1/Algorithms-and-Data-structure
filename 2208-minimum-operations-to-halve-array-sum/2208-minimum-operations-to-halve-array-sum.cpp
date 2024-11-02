class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> heap (nums.begin(), nums.end()) ;
        double target = 0;
        for(double num :nums) {
            target += num;
        }
        target /= 2;
        int ans = 0;
        while(target > 0) {
            ans++;
            double x = heap.top();
            heap.pop();
            target -= (x/2);
            heap.push(x/2);
        }
        return ans;
    }
};