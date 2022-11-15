class Solution {
public:
    bool onsame(vector<int>& p1,vector<int>& p2){
        return p1[0]==p2[0] || p1[1]==p2[1];
    }
    void dfs(vector<vector<int>>& st, vector<bool>& vis,int u){
        vis[u]=true;
        for(int i=0;i<st.size();i++){
            if(!vis[i] && onsame(st[u],st[i]))dfs(st,vis,i);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<bool> vis(stones.size(),false);
        int ans=0;
        for(int i=0;i<stones.size();i++){
            if(!vis[i]){
                dfs(stones,vis,i);
                ans++;
            }
        }
        return stones.size()-ans;
    }
};