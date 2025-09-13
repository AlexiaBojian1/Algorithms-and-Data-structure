class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int left = 0;
        int result = 0;
        int right = 0;
        while(right < s.length()) {
            freq[s[right]] ++;
            while(freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};