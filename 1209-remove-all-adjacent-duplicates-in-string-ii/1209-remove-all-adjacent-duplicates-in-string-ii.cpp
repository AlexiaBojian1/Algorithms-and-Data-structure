class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        
        for(int i = 0;i<s.length(); i++) {
            int count = 1;
            if(!st.empty() && s[i] == st.top().first) {
                count += st.top().second;
                st.pop();
            }
            st.push({s[i],count});
            if(count == k) {
               st.pop();
            }
        }

        string ans = "";
        while(!st.empty()) {
            int freq = st.top().second;
            char c = st.top().first;
            while(freq) {
                ans += c;
                freq --;
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};