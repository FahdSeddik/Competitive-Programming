class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size(),depth=0;
        vector<int> dist(n,INT_MAX),dist2(n,INT_MAX);
        vector<bool> vis(n,false),vis2(n,false);
        queue<int> q;
        q.push(node1);
        while(!q.empty()){
            int u = q.front();q.pop();
            if(vis[u])continue;
            dist[u]=depth++;
            vis[u]=true;
            if(edges[u]!=-1)q.push(edges[u]);
        }
        q = queue<int>();
        q.push(node2);depth=0;
        while(!q.empty()){
            int u = q.front();q.pop();
            if(vis2[u])continue;
            dist2[u]=depth++;
            vis2[u]=true;
            if(edges[u]!=-1)q.push(edges[u]);
        }
        int mn=INT_MAX,ans=-1;
        for(int i=0;i<n;i++){
            if(max(dist[i],dist2[i])<mn)mn=max(dist[i],dist2[i]),ans=i;
        }
        return ans;
    }
};