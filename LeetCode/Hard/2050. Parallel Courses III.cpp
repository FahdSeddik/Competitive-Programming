static const int fast_io = [](){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    return 0;
}();

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indegree(n+1);
        vector<vector<int>> adj(n+1);
        for(auto& d : relations){
            indegree[d[1]]++;
            adj[d[0]].push_back(d[1]);
        }
        queue<int> q;
        vector<int> dist=time;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0)q.push(i);
            ans=max(ans,time[i-1]);
        }
        int size=q.size();
        for(;!q.empty();size=q.size()){
            while(size--){
                int x = q.front();q.pop();
                for(auto u : adj[x]){
                    dist[u-1]=max(dist[u-1],dist[x-1]+time[u-1]);
                    ans=max(dist[u-1],ans);
                    indegree[u]--;
                    if(indegree[u]==0)q.push(u);
                }
            }
        }
        return ans;
    }
};