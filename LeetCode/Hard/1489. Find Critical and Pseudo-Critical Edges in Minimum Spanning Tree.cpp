class Solution {
    int par[101],E;
public:
    int find(int x){
        return x==par[x] ? x:par[x]=find(par[x]);
    }
    int findMST(vector<vector<int>>& edges,int& size,int exc=-1,int inc=-1){
        iota(par,par+101,0);
        int weight=0;
        if(inc!=-1){
            par[edges[inc][0]]=edges[inc][1];
            weight+=edges[inc][2];
            size++;
        }
        for(int i=0;i<E;i++)if(i!=exc){
            int x = find(edges[i][0]);
            int y = find(edges[i][1]);
            if(x!=y) par[x]=y,weight+=edges[i][2],size++;
        }
        return weight;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        E=edges.size();
        for(int i=0;i<E;i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[&](const vector<int>&a,const vector<int>& b){
            return a[2]<b[2];
        });
        int size=0;
        int mn = findMST(edges,size);
        vector<vector<int>> ans(2);
        for(int i=0;i<E;i++){
            size=0;
            int temp = findMST(edges,size,i);
            if(size<n-1 || temp>mn){
                ans[0].push_back(edges[i][3]);
            }else{
                size=0;
                int forced = findMST(edges,size,i,i);
                if(forced==mn)ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};