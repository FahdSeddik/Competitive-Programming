class Solution {
    int par[1001];
public:
    int find(int x){
        return x==par[x] ? x:par[x]=find(par[x]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        iota(par,par+points.size(),0);
        vector<pair<int,pair<int,int>>> manhattan;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                manhattan.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),{i,j}});
            }
        }
        sort(manhattan.begin(),manhattan.end());
        int ans=0;
        for(const auto& dd : manhattan){
            int x = find(dd.second.first);
            int y = find(dd.second.second);
            if(x!=y){
                par[x]=y;
                ans+=dd.first;
            }
        }
        return ans;
    }
};