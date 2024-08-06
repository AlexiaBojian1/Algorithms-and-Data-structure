class Solution {
public:
    bool isPalindrome(string s) {
        int i;
        int j;
        for(i = 0 , j = s.size()-1; i<j;i++,j--) {
            while(i<j && !isalnum(s[j])) {
                j--;
            }
            while(i<j && !isalnum(s[i])) {
                i++;
            }
            if(tolower(s[i]) != tolower(s[j])) {
                return false;
            }
        }
        return true;
        
    }
};