class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n,0,0,"",result);
        return result;
    }
   void generate(int n,int open, int close,string s, vector<string> & result) {
       if(open == n && close == n) {
           result.push_back(s);
           return;
       }
       if(open < n){
           generate(n, open+1,close, s + '(', result);
       }
       if(close < open) {
           generate(n, open,close +1, s + ')', result);
       }
   }

};