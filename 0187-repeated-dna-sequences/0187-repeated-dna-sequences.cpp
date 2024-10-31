class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<string,int> freq;
        for(int i = 0; i + 10 <= s.length(); i++) {
            string aux = s.substr(i,10);
            if(freq.find(aux) == freq.end()) {
                freq[aux] = 1;
            } else {
                freq[aux]++;
            }
            if(freq[aux] == 2) {
                result.push_back(aux);
            }
        }
        return result;
    }
};