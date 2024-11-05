class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        for(int i = 1;i <=9 ;i++) {
            dfs(i, n-1, k, result);
        }
        return result;
    }

    void dfs(int num, int n , int k , vector<int> & result) {
        if(n == 0) {
            result.push_back(num);
            return;
        }

        int last_digit = num%10;

        if(last_digit+k <= 9) {
            dfs(num*10 + last_digit + k, n - 1, k , result);
        }

        if(k > 0 && last_digit - k >= 0) {
            dfs(num* 10 + last_digit - k, n-1, k , result);
        }
    }
};