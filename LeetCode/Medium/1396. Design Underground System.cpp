class UndergroundSystem {
    unordered_map<int,pair<string,int>> checkins;
    unordered_map<string,unordered_map<string,pair<int,int>>> times;
public:
    UndergroundSystem() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    void checkIn(int id, string stationName, int t) {
        if(checkins.count(id))return;
        checkins[id]={stationName,t};        
    }
    
    void checkOut(int id, string stationName, int t) {
        if(!checkins.count(id))return;
        times[checkins[id].first][stationName].first+=t-checkins[id].second;
        times[checkins[id].first][stationName].second++;
        checkins.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)times[startStation][endStation].first/times[startStation][endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */