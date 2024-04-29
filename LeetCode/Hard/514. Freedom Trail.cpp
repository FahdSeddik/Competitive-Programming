class Solution {
public:
    int findRotateSteps(string ring, string key) {
        queue<pair<int,int>> q;
        q.push({0, 0});
        int n = ring.size(), m = key.size(), size = 1, depth = 0;
        bool vis[n][m];
        memset(vis, 0, sizeof(vis));
        for(;!q.empty(); size = q.size(), depth++) {
            while (size--) {
                auto u = q.front();q.pop();
                if(u.second>=m)return depth;
                if(vis[u.first][u.second])continue;
                vis[u.first][u.second] = true;
                q.push({(u.first+1)%n, u.second});
                q.push({(n+u.first-1)%n, u.second});
                if(ring[u.first] == key[u.second])q.push({u.first, u.second+1});
            }
        }
        return -1;
    }
};