class Logger {
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = lastTime_.find(message);

        // First time we see this message → always print
        if (it == lastTime_.end()) {
            lastTime_[message] = timestamp;
            return true;
        }

        // Seen before: check the 10-second rule
        if (timestamp - it->second >= 10) {
            it->second = timestamp;  // update to latest time
            return true;
        }

        return false;  // too soon – suppress
    }
    
private:
    unordered_map<string, int> lastTime_;    
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */