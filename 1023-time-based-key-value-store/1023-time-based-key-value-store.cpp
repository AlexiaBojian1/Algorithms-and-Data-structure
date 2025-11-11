class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> keyTimeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyTimeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(keyTimeMap.find(key) == keyTimeMap.end()) {
            return "";
        }

        if(timestamp < keyTimeMap[key][0].first) {
            return "";
        }

        int left = 0;
        int right = keyTimeMap[key].size();

        while(left < right) {
            int mid = (left + right) / 2;
            if(keyTimeMap[key][mid].first <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        if(right == 0) {
            return "";
        }

        return keyTimeMap[key][right - 1].second;
    }    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */