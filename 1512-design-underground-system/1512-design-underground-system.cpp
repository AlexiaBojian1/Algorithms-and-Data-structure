class UndergroundSystem {
private:
    unordered_map<string , pair<double, double>> journeyData;
    unordered_map<int, pair<string, int>> checkinData;    
public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        checkinData[id] = {stationName , t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkInInfo = checkinData[id];
        string start = checkInInfo.first;
        int starttime = checkInInfo.second;

        string route = start + "->" + stationName;

        auto &routeStats = journeyData[route];
        double triptime = t - starttime;
        routeStats.first += triptime;
        routeStats.second += 1;

        checkinData.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "->" + endStation;
        auto routeData = journeyData[route];
        double triptime = routeData.first;
        double total = routeData.second;
        return triptime/total;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */