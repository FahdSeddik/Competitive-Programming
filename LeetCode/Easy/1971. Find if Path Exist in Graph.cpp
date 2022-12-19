class Solution {
public:
    
    int find(int* e,int x){
        return x==e[x] ? x:e[x]=find(e,e[x]);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1 || source==destination)return true;
        int e[n];
        for(int i=0;i<n;i++)e[i]=i;
        for(auto E : edges){
            int x=find(e,E[0]);
            int y=find(e,E[1]);
            e[x]=e[y];
        }
        if(find(e,source)==find(e,destination))return true;
        return false;
    }
};