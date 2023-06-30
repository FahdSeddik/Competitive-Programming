class Solution {
    const int MOD = 1e9 + 7;
    int n, finish;
    vector<int> cityLocations;
public:
    int countRoutes(int currCity, int fuel, vector<vector<int>> &dp) {
        if(fuel < 0) return 0;
        if(dp[currCity][fuel] != -1) return dp[currCity][fuel];
        int cnt = 0;
        if(currCity == finish) ++cnt;
        for(int nextCity=0; nextCity<n; ++nextCity) {
            if(nextCity == currCity) continue;
            cnt += countRoutes(nextCity, fuel-abs(cityLocations[nextCity]-cityLocations[currCity]), dp);
            if(cnt >= MOD) cnt -= MOD;
        }
        return dp[currCity][fuel]=cnt;
    }
    int countRoutes(vector<int> &locations, int start, int finish, int fuel) {
        n = (int)locations.size();
        this->finish = finish;
        cityLocations = locations;        
        vector<vector<int>> dp(n, vector<int>(fuel+1, -1));
        return countRoutes(start, fuel, dp);
    }
};