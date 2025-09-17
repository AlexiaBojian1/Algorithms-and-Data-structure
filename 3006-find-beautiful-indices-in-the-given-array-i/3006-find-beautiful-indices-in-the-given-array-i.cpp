class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> a_indices;
        vector<int> b_indices;
        vector<int> result;

        for(int i = 0; i < s.length(); i++) {
            if(s.substr(i, a.size()) == a) {
                a_indices.push_back(i);
            }
        }

        for(int i = 0; i < s.length(); i++) {
            if(s.substr(i, b.size()) == b) {
                b_indices.push_back(i);
            }
        }

        int j = 0;
        for(int i : a_indices) {
            while(j < b_indices.size() && b_indices[j] < i - k) {
                j++;
            }

            if(j < b_indices.size() && abs(b_indices[j] - i) <= k) {
                result.push_back(i);
            }
        }

        return result;

    }
};