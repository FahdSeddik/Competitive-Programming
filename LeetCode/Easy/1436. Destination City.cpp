class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> cities;
        for(auto& path : paths) cities[path[0]]|=1, cities[path[1]]|=2;
        for(auto& [city, bits] : cities) if(bits == 2)return city;
        return "";
    }
};