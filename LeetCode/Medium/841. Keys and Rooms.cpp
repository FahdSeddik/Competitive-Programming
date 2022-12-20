class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int e[n+1];
        memset(e,0,sizeof(e));
        queue<int> q;
        q.push(0);
        e[0]=1;
        while(!q.empty()) {
            int i = q.front(); q.pop();
            for (auto k : rooms[i]) {
                if(!e[k])e[k]=1,q.push(k);
            }
        }
        for (int i = 1; i < n; i++) {
            if (!e[i])return false;
        }
        return true;
    }
};