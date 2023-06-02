class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for(const auto& v : prerequisites){
            indegree[v[0]]++;
            adj[v[1]].push_back(v[0]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)if(indegree[i]==0)q.push(i);
        int size=q.size(),cnt=0;
        for(;!q.empty();size=q.size()){
            while(size--){
                int u = q.front();q.pop();
                cnt++;
                for(auto v:adj[u]){
                    indegree[v]--;
                    if(indegree[v]==0)q.push(v);
                }
            }
        }
        return cnt==numCourses;
    }
};