class Solution {
public:
    vector<int> topo(vector<vector<int>>& adj,vector<int>&ind,int& n){
        queue<int> q;
        for(int i=0;i<n;i++)if(ind[i]==0)q.push(i);
        vector<int> res;
        while(!q.empty()){
            int u = q.front();q.pop();
            res.push_back(u);
            for(int v:adj[u]){
                ind[v]--;
                if(ind[v]==0)q.push(v);
            }
        }
        for(int i=0;i<n;i++)if(ind[i])return {};
        return res;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<n;i++){
            if(group[i]==-1)group[i]=m++;
        }
        vector<vector<int>> adj1(m),adj2(n);
        vector<int> ind1(m),ind2(n);
        for(int i=0;i<n;i++){
            int to_i = group[i];
            for(int from:beforeItems[i]){
                int from_j = group[from];
                if(to_i!=from_j)adj1[from_j].push_back(to_i),ind1[to_i]++;
                adj2[from].push_back(i);
                ind2[i]++;
            }
        }
        vector<int> sorted1=topo(adj1,ind1,m),sorted2=topo(adj2,ind2,n);
        if(sorted1.empty() || sorted2.empty())return {};
        vector<vector<int>> itgp(m);
        for(int i:sorted2)itgp[group[i]].push_back(i);
        vector<int> ans;
        for(int i:sorted1){
            for(int item:itgp[i])ans.push_back(item);
        }
        return ans;
    }
};