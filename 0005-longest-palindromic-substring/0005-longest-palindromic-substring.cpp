class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        int maxlen = 0;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            int len1 = expandfromCenter(s,i,i);
            int len2 = expandfromCenter(s,i,i+1);
            maxlen = max(len1, len2);
            if(maxlen > end - start) {
                start = i - (maxlen - 1)/2;
                end = i + maxlen/2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int expandfromCenter(string &s, int left, int right) {
        while(left >= 0 && right<s.size() && s[left] == s[right]) {
            left --;
            right++;
        }
        return right - left -1;
    }
};