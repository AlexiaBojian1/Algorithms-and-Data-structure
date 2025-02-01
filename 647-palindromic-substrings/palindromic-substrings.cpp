class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i <= s.size(); i++) {
            ans += expandfromCenters(s,i,i);
            ans += expandfromCenters(s,i,i+1);
        }
        return ans;
    }

    int expandfromCenters(string s, int left, int right) {
        int ans = 0;
        while(left >= 0 && right < s.size()) {
            if(s[left] != s[right]) {
                break;
            }
            left--;
            right++;
            ans++;
        }
        return ans;
    }
};