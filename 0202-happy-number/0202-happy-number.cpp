class Solution {
public:
    int sumsquares(int x) {
        int s = 0;
        while(x > 0) {
            int d = x % 10;
            s += d * d;
            x = x / 10;
        }

        return s;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = sumsquares(n);
        while(fast != 1 && slow != fast) {
            slow = sumsquares(slow);
            fast = sumsquares(sumsquares(fast));
        }    

        return fast == 1;
    }
};