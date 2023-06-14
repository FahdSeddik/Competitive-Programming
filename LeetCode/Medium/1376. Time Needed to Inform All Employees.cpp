class Solution {
    int ans;
public:
    void dfs(vector<vector<int>>& adj,vector<int>& informTime,int src,int infrm){
        for(int u : adj[src]){
            dfs(adj,informTime,u,informTime[src]+infrm);
        }
        ans = max(ans,infrm+informTime[src]);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        ans=0;
        for(int i=0;i<n;i++)if(manager[i]!=-1){
            adj[manager[i]].push_back(i);
        }
        dfs(adj,informTime,headID,0);
        return ans;
    }
};