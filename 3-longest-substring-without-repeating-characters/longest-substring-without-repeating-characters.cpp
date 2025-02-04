class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> freq;
        int right = 0;
        int left = 0;
        int res = 0;
        while(right < s.length()) {
            freq[s[right]]++;
            while(freq[s[right]] > 1) {
                freq[s[left]] --;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};