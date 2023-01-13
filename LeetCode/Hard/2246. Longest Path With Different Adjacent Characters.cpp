class Solution {
    int ans;
public:
    int dfs(vector<vector<int>>& adj,string& s,int src=0){
        int mx1=0,mx2=0;
        for(const auto& u : adj[src]){
            int temp = dfs(adj,s,u);
            ans = max(ans,temp);
            if(s[u]!=s[src]){
                if(temp>mx1)mx2=mx1,mx1=temp;
                else if(temp>mx2)mx2=temp;
            }
        }
        ans = max(mx1+mx2+1,ans);
        return mx1+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++)adj[parent[i]].push_back(i);
        ans=1;
        dfs(adj,s);
        return ans;
    }
};