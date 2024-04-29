class Solution {
public:
    string reverseOnlyLetters(string s) {
        int len = (int)s.size();
        int start = 0;
        int end = len-1;
        while(start < end) {
            while(start < end && !isalpha(s[start])){
                start++;
            }
            while(start < end && isalpha(s[end]) == false) {
                end--;
            }
            if(start < end) {
                char temp;
                temp = s[start];
                s[start] = s[end];
                s[end] = temp;
                start++;
                end--;
            }
        }
        return s;
    }
};