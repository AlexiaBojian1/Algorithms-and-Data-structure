class Solution {
public:
    vector<double> generatePossibleResults(double& a, double& b) {
        vector<double> res = {a + b, a - b, b - a,  a * b};
        if(a) {
            res.push_back(b / a);
        }
        if(b) {
            res.push_back(a / b);
        }
        return res;
    }

    bool checkIfResultReached(vector<double> list) {
        if(list.size() == 1) {
            return abs(list[0] - 24) <= 0.1;
        }

        for(int i = 0; i < list.size(); i++) {
            for(int j = i + 1; j < list.size(); j++) {
                vector<double> newList;
                for(int k = 0; k < list.size(); k++) {
                    if(k != j && k != i) {
                        newList.push_back(list[k]);
                    } 
                }

                for(double& res : generatePossibleResults(list[i],list[j])) {
                    newList.push_back(res);
                    if(checkIfResultReached(newList)) {
                        return true;
                    }
                    newList.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> list(cards.begin(), cards.end());
        return checkIfResultReached(list);
        
    }
};