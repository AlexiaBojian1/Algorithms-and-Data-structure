class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() == 0 || s.length() == 0) {
            return "";
        }

        unordered_map<char , int> freq;
        for(char c : t) {
            freq[c]++;
        }

        int required = freq.size();
        int left = 0;
        int right = 0;
        int formed = 0;
        unordered_map<char , int> windowCount;
        int ans[3] = {-1, 0, 0}; // size, left, right
        while(right < s.length()) {
            char c = s[right];
            windowCount[c] ++;
            if(freq.find(c) != freq.end() && windowCount[c] == freq[c]) {
                formed++;
            }

            while(left <= right && formed == required) {
                c = s[left];
                if(ans[0] == -1 || right - left + 1 < ans[0]) {
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }
                windowCount[c] --;
                if(freq.find(c) != freq.end() && windowCount[c] < freq[c]) {
                    formed --;
                }
                left++;
            }
            right++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[2] - ans[1] + 1);
    }
};