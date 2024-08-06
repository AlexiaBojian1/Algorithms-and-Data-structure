class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u'};
        int count = 0;
        int right = k;
        int left = 0;
        for(int i = 0; i < k; i++) {
            count  = count + vowels.count(s[i]);
        }
        int res = count;
        while(right < s.length()) {
            count = count + vowels.count(s[right]) - vowels.count(s[left]);
            right++;
            left++;
            res = max(res,count);
        }
        return res;
    }
};