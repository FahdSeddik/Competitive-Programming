class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;
        int n = routes.size(), mx=0;
        for(const auto& stops : routes){
            for(int stop : stops)mx=max(mx,stop);
        }
        if(mx<target)return -1;
        vector<int> dist(mx+1,INT_MAX);
        dist[source]=0;
        int isReduce=true;
        while(isReduce){
            isReduce=false;
            for(const auto& stops: routes){
                int mn = n+1;
                for(int stop: stops)mn = min(mn,dist[stop]);
                mn++;
                for(int stop: stops){
                    if(dist[stop]>mn)dist[stop]=mn,isReduce=true;
                }
            }
        }
        return dist[target]<=n ? dist[target]:-1;
    }
};