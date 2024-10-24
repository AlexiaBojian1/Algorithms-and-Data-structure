class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string sample = "123456789";
        vector<int> nums;
        int lowlen = to_string(low).length();
        int highlen = to_string(high).length();
        for(int len = lowlen; len <= highlen; len++) {
            for(int start = 0; start <= 9-len; start++) {
                int num = stoi(sample.substr(start, len));
                if(num >= low && num <= high) {
                    nums.push_back(num);
                }
            }
        }
        return nums;
    }
};