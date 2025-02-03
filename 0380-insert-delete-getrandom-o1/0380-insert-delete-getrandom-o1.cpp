class RandomizedSet {
private:
    unordered_map<int, int> dict;
    vector<int> list;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(dict.find(val) != dict.end()) return false;

        dict[val] = list.size();
        list.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(dict.find(val) == dict.end()) return false;

        int index = dict[val];
        int lastElement = list.back();

        list[index] = lastElement;
        dict[lastElement] = index;

        list.pop_back();
        dict.erase(val);
        return true;
        
    }
    
    int getRandom() {
        return list[rand() % list.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */