class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
           vector<int> a_indices, b_indices;
        vector<int> result;

        int n = s.size();
        int a_len = a.size(), b_len = b.size();

        // Step 1: Find all starting indices where `a` is found in `s`
        for (int i = 0; i <= n - a_len; i++) {
            if (s.substr(i, a_len) == a) {
                a_indices.push_back(i);
            }
        }

        // Step 2: Find all starting indices where `b` is found in `s`
        for (int i = 0; i <= n - b_len; i++) {
            if (s.substr(i, b_len) == b) {
                b_indices.push_back(i);
            }
        }

        // Step 3: Use two pointers to find valid pairs (i, j)
        int j = 0;
        for (int i : a_indices) {
            // Move `j` to the first valid `b_indices[j]` such that `b_indices[j] >= i - k`
            while (j < b_indices.size() && b_indices[j] < i - k) {
                j++;
            }
            
            // Check if `b_indices[j]` satisfies `|j - i| <= k`
            if (j < b_indices.size() && abs(b_indices[j] - i) <= k) {
                result.push_back(i);
            }
        }

        return result;
    }
};