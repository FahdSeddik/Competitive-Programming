class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int all_visited = (1<<n)-1;
        queue<pair<int,pair<int,int>>> q;
        unordered_set<int> vis;
        for(int i=0;i<n;i++){
            q.push({1<<i,{i,0}});
            vis.insert((1<<i)*16+i);
        }
        while(!q.empty()){
            auto x = q.front();q.pop();
            if(x.first==all_visited){
                return x.second.second;
            }
            for(int u : graph[x.second.first]){
                int new_mask = x.first | (1<<u);
                int hash_value = new_mask * 16+u;
                if(!vis.count(hash_value)){
                    vis.insert(hash_value);
                    q.push({new_mask,{u,x.second.second+1}});
                }
            }
        }
        return -1;
    }
};