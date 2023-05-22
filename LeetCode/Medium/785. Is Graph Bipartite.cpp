class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& color,int i,int col){
        color[i]=col;
        for(auto u : graph[i]){
            if(color[u]==color[i])return false;
            if(color[u]==0 && !dfs(graph,color,u,col==1 ? 2:1))return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        for(int i=0;i<n;i++){
            if(color[i]==0){
                if(!dfs(graph,color,i,1))return false;
            }
        }
        return true;
    }
};