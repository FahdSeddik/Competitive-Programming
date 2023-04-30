class Solution {
public:
    int find(vector<int>& par,int x){
        return x==par[x] ? x:par[x]=find(par,par[x]);
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> par1(n),par2;
        iota(par1.begin(),par1.end(),0);
        int conn=0;
        for(const auto& v : edges)if(v[0]==3){
            int x = find(par1,v[1]-1),y=find(par1,v[2]-1);
            conn+=x!=y;
            par1[x]=par1[y];
            if(conn==n-1)return edges.size()-conn;
        }
        par2=par1;
        int p1=0,p2=0;
        for(const auto& v : edges){
            if(v[0]==1){
                int x = find(par1,v[1]-1),y=find(par1,v[2]-1);
                p1+=x!=y;
                par1[x]=par1[y];
            }else if(v[0]==2){
                int x = find(par2,v[1]-1),y=find(par2,v[2]-1);
                p2+=x!=y;
                par2[x]=par2[y];
            }
            if(p1+conn==n-1 && p2+conn==n-1)return edges.size()-(p1+p2+conn);
        }
        return -1;
    }
};