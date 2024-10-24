class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> deletePos;
        int n = s.size();
        for(int i = 0;i<n ;i++) {
            if(s[i] == ')') {
                if(!deletePos.empty() && s[deletePos.back()] == '(') {
                    deletePos.pop_back();
                } else {
                    deletePos.push_back(i);
                }
            } else if(s[i] == '(') {
                 deletePos.push_back(i);   
            }
        }

        if(deletePos.size() == 0) {
            return s;
        }

        int m = deletePos.size();
        int cur = 0;
        string res = "";
        for(int i = 0; i < n ;i++) {
            if(cur < m && i == deletePos[cur]){
                cur++;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};