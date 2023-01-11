class Solution {
public:
    int dfs(vector<vector<int>> & adj, vector<bool>& hasApple,int src=0,int prev=-1,int d=0){
        int score=0,temp;
        for(const auto &e : adj[src])if(e!=prev){
	        temp=dfs(adj,hasApple,e,src,d+1);
	        if(temp) score+=temp-d;
	    }
        return score||hasApple[src] ? score+d:0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(const auto &v : edges)adj[v[0]].push_back(v[1]),adj[v[1]].push_back(v[0]);
        return dfs(adj,hasApple)*2;
    }
};