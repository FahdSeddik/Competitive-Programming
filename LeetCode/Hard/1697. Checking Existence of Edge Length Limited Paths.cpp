class Solution {
    vector<int> parent;
public:
    int find(int x){
        return x==parent[x] ? x:parent[x]=find(parent[x]);
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        for(int i=0;i<queries.size();i++)queries[i].push_back(i);
        iota(parent.begin(),parent.end(),0);
        sort(edgeList.begin(),edgeList.end(),[&](const vector<int>& a,const vector<int>& b){
            return a[2]<b[2];
        });
        sort(queries.begin(),queries.end(),[&](const vector<int>& a,const vector<int>& b){
            return a[2]<b[2];
        });
        int i=0;
        vector<bool> ans(queries.size());
        for(const auto& q : queries){
            while(i<edgeList.size() && edgeList[i][2]<q[2]){
                parent[find(edgeList[i][0])]=parent[find(edgeList[i][1])];
                i++;
            }
            if(find(q[0])==find(q[1]))ans[q[3]]=true;
        }
        return ans;
    }
};