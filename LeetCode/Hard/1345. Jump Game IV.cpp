class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,list<int>> mp;
        for(int i=n-1;i>=0;i--)mp[arr[i]].push_back(i);
        vector<bool> vis(n);
        queue<int> q;
        q.push(0);
        int size=1,depth=0;
        for(;!q.empty();size=q.size(),++depth){
            while(size--){
                int cur = q.front();q.pop();
                if(cur==n-1)return depth;
                vis[cur]=true;
                if(cur>0 && !vis[cur-1])q.push(cur-1);
                if(cur<n-1 && !vis[cur+1])q.push(cur+1);
                for(const auto& v : mp[arr[cur]])if(!vis[v])q.push(v);
                mp[arr[cur]].clear();
            }
        }
        return depth;
    }
};