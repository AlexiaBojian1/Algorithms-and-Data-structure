struct Transaction {
    string name, city;
    int time, money;
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<Transaction> info;
        vector<string> result;
        
        for (auto transaction : transactions) {
            Transaction d;
            stringstream ss(transaction);
            string segment;
            getline(ss, d.name, ',');
            getline(ss, segment, ',');
            d.time = stoi(segment);
            getline(ss, segment, ',');
            d.money = stoi(segment);
            getline(ss, d.city, ',');
            info.push_back(d);
        }
        
        for (int i = 0; i < info.size(); i++) {
            bool flag = false;
            if (info[i].money > 1000) {
                result.push_back(transactions[i]);
                continue;
            }
            
            for (int j = 0; j < info.size(); j++) {
                if (i == j) continue;
                if (info[i].name == info[j].name && info[i].city != info[j].city && abs(info[i].time - info[j].time) <= 60) {
                    flag = true;
                    break;
                }
            }
            
            if (flag) result.push_back(transactions[i]);
        }
        
        return result;
    }
};