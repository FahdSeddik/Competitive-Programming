class Solution {
    vector<int> par;
public:
    int find(int x){
        return x==par[x] ? x:par[x]=find(par[x]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        par.resize(n);
        iota(par.begin(),par.end(),0);
        int ans=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)if(isConnected[i][j]){
                int u = find(i),v=find(j);
                if(u!=v)par[u]=v,ans--;
            }
        }
        return ans;
    }
};