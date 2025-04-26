class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        result.reserve(s.size() + spaces.size());
        int spaceindex = 0;
        for(int stringindex = 0; stringindex < s.size(); stringindex++) {
            if(spaceindex < spaces.size() && stringindex == spaces[spaceindex]) {
                result += ' ';
                ++spaceindex;
            }
            result += s[stringindex];
        }
        return result;
    }
};