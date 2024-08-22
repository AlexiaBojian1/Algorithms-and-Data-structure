class Solution {
public:
    int maxNumberOfBalloons(string text) {
         int bCount = 0, aCount = 0, lCount = 0, oCount = 0, nCount = 0;
          for (int i = 0; i < text.length(); i++) {
            if (text[i] == 'b') {
                bCount++;
            } else if (text[i] == 'a') {
                aCount++;
            } else if (text[i] == 'l') {
                lCount++;
            } else if (text[i] == 'o') {
                oCount++;
            } else if (text[i] == 'n') {
                nCount++;
            }
        }
         lCount = lCount / 2;
        oCount = oCount / 2;
         return min({bCount, aCount, lCount, oCount, nCount});
        
        
    }
};