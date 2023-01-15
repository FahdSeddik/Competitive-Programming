class Solution {
    int parent[30001];
public:
    int find(int x){
        return x==parent[x] ? x : parent[x]=find(parent[x]);
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int ans=vals.size();
        //For each value hold number of paths
        //start with 1 (the node itself)
        vector<pair<int,int>> ve;
        for(int i=0;i<ans;i++)ve.push_back({vals[i],1});
        //initialize parent array for DSU
        iota(parent,parent+30001,0);
        //Sort edges according to max vals ascendingly
        sort(edges.begin(),edges.end(),[&](vector<int>& a,vector<int>& b){
            return max(vals[a[0]],vals[a[1]])<max(vals[b[0]],vals[b[1]]);
        });
        for(const auto& e : edges){
            int x = find(e[0]);
            int y = find(e[1]);
            if(ve[y].first==ve[x].first){//if same value
                //pick one to merge onto
                parent[x]=y;
                //update ans with possible paths
                //calculated as product of number of paths
                ans+=ve[y].second*ve[x].second;
                //merge number of paths onto the other node
                ve[y].second+=ve[x].second;
            }else if(ve[x].first>ve[y].first){//if value is larger
                parent[y]=x;//merge on smaller
            }else parent[x]=y;
        }
        return ans;
    }
};