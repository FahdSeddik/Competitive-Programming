class Solution {
    vector<int> dx={1,-1,0,0},dy={0,0,1,-1};
    vector<vector<int>> dist;
    int n,m;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        n=heights.size(),m=heights[0].size();
        dist.resize(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int size=1;
        for(;!pq.empty();size=pq.size()){
            while(size--){
                auto x = pq.top();pq.pop();
                int i=x.second.first,j=x.second.second,tot=x.first;
                if(tot > dist[i][j])continue;
                if(i==n-1 && j==m-1)return tot;
                for(int d=0;d<4;d++){
                    int r=i+dx[d],c=j+dy[d];
                    if(r<0 || c<0 || r>=n || c>=m)continue;
                    int dis = max(tot,abs(heights[i][j]-heights[r][c]));
                    if(dis<dist[r][c])dist[r][c]=dis,pq.push({dis,{r,c}});
                }
            }
        }
        return -1;
    }
};