class Solution {
public:
    string minWindow(string s, string t) {
        int right = 0;
        int formed = 0;
        int left = 0;
        int ns = s.length();
        int nt = t.length();
        if(ns < nt) {
            return "";
        }
        unordered_map<char, int> freq;
        for(char ch : t) freq[ch] ++;
        int requiered = freq.size();
        unordered_map<char, int> window_count;
        int ans[3] = {-1, 0, 0};

        while(right < s.length()) {
            window_count[s[right]]++;
            if(freq.find(s[right]) != freq.end() && window_count[s[right]] == freq[s[right]]) {
                formed++;
            }

            while(left <= right && formed == requiered) {
                char c = s[left];
                if(ans[0] > right - left + 1 || ans[0] == -1) {
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }
                window_count[c]--;
                if(freq.find(c) != freq.end() && window_count[c] < freq[c]) {
                    formed --;
                }
                left++;
            }
            right++;
        }

        return ans[0] == -1 ? "" : s.substr(ans[1], ans[2] - ans[1] + 1);
    }
};