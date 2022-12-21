class Solution {
public:
    vector<int> e,p;
    int find(int x){
        if(e[x]!=x){
            int y=find(e[x]);
            p[x]^=p[e[x]];
            e[x]=y;
        }
        return e[x];
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        e.resize(n+1);p.resize(n+1,0);
        iota(e.begin(),e.end(),0);
        for(auto &v: dislikes){
            int x=v[0],y=v[1];
            if(e[y]==y)e[y]=x,p[y]=1;
            else if(find(x)==find(y) && p[x]==p[y])return false;
        }
        return true;
    }
};