class Solution {
    vector<int> ans;
public:
    vector<int> dfs(vector<vector<int>>&adj,string& labels, int src=0,int prev=-1){
        vector<int> child(26);
        child[labels[src]-'a']++;
        for(const auto& v : adj[src])if(v!=prev){
            vector<int> f = dfs(adj,labels,v,src);
            for(int i=0;i<26;i++)child[i]+=f[i];
        }
        ans[src]+=child[labels[src]-'a'];
        return child;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n);
        vector<vector<int>> adj(n);
        for(const auto& e: edges)adj[e[0]].push_back(e[1]),adj[e[1]].push_back(e[0]);
        vector<int> dct = dfs(adj,labels);
        return ans;
    }
};