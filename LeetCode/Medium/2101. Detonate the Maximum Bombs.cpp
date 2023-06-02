class Solution {
    int res;
public:
    int iswithin(vector<int>& a,vector<int>& b){
        long long d = (long long)(a[0]-b[0])*(a[0]-b[0])+(long long)(a[1]-b[1])*(a[1]-b[1]);
        bool c1 = d<=(long long)b[2]*b[2],c2=d<=(long long)a[2]*a[2];
        if(c1 && c2)return 2;
        if(c1)return 1;
        if(c2)return 0;
        return -1;
    }
    void dfs(vector<vector<int>>& adj,vector<bool>& vis,int src){
        vis[src]=true,res++;
        for(auto u : adj[src])if(!vis[u])dfs(adj,vis,u);
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        res=0;
        vector<bool> vis(n);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int w = iswithin(bombs[i],bombs[j]);
                if(w==2)adj[i].push_back(j),adj[j].push_back(i);
                else if(w==1)adj[j].push_back(i);
                else if(w==0)adj[i].push_back(j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            dfs(adj,vis,i);
            vis = vector<bool>(n);
            ans = max(ans,res);
            res=0;
        }
        return ans;
    }
};