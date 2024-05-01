class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int right = 0;
        int left = 0;
        int cost = 0;
        int res = INT_MIN;
        int n = s.length();
        while(right < n){
            cost = cost + abs(int(s[right])-int(t[right]));
            while(cost > maxCost) {
                cost = cost - abs(int(s[left])-int(t[left]));
                left++;
            }
            res = max(res,right-left+1);
            right++;
        }
        return (res != INT_MIN)? res : 0;
    }
};