#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class UndergroundSystem {
public:
    unordered_map<string, pair<long long, int>> m;
    unordered_map<int, pair<string, int>> id_in;

    UndergroundSystem() {
        m = {};
        id_in = {};
    }
    
    void checkIn(int id, string stationName, int t) {
        id_in[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto p = id_in[id];
        id_in.erase(id);
        string up = p.first;
        int up_t = p.second;
        up = up + '-' + stationName;
        if (m.find(up) == m.end()) m[up] = {t-up_t, 1};
        else {
            m[up].first += t-up_t;
            m[up].second += 1;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string up = startStation + '-' + endStation;
        if (m.find(up) == m.end()) return 0;
        if (m[up].second == 1) return m[up].first;
        return (double)(m[up].first) / m[up].second;
    }
};
