class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i = 0;
        int j = tokens.size() - 1;
        int score = 0;
        sort(tokens.begin(), tokens.end());
        while(i <= j) {
            if(tokens[i] <= power) {
                power -= tokens[i];
                score += 1;
                i++;
            } else if(i < j && score > 0) {
                power += tokens[j];
                score -= 1;
                j--;
            } else {
                return score;
            }
        }
        return score;
    }
};