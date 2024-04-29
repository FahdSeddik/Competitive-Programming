class Solution {
    vector<vector<int>>adj;
    vector<int>dp;
    vector<int>ans;
    int n;
public:
    void dfs(int parent,int node,int depth){
        ans[0]+=depth;
        for(auto it:adj[node])if(it!=parent){
            dfs(node,it,depth+1);
            dp[node]=dp[node]+dp[it];
        }
    }
    void dfs2(int parent,int node){
        for(auto it:adj[node])if(it!=parent){
            ans[it]=ans[node]-dp[it]+(n-dp[it]);
            dfs2(node,it);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dp.resize(n,1), ans.resize(n), this->n=n;
        dfs(-1,0,0), dfs2(-1,0);
        return ans;
    }
};