class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;
        while(start < end) {
            char aux;
            aux = s[start];
            s[start] = s[end];
            s[end] = aux;
            start ++;
            end--;
        }
    }
};