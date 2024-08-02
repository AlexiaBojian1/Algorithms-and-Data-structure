class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start = 0;
        int end = (int)s.size();
        while(start < end) {
            while(start < end && !isalpha(s[start])){
                start++;
            }
            while(start < end && isalpha(s[end]) == false) {
                end--;
            }
            if(start < end) {
                char aux = s[start];
                s[start] = s[end];
                s[end] = aux;
                start++;
                end--;
            }   
        }
        return s;
    }
};