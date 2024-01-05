class Solution {
    vector<int> dx{1,-1,0,0},dy{0,0,1,-1};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,int>> q;
        int m = isWater.size(),n = isWater[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)if(isWater[i][j])q.push({i,j}),isWater[i][j]^=(1<<11)+1;
        }
        int size = q.size(),depth=0;
        for(;!q.empty();size=q.size(),depth++){
            while(size--){
                auto x = q.front();q.pop();
                for(int d=0;d<4;d++){
                    int r = x.first+dx[d],c=x.second+dy[d];
                    if(r<0 || c<0 || r>=m || c>=n || (isWater[r][c]&(1<<11)))continue;
                    isWater[r][c]=depth+1;
                    isWater[r][c]|=(1<<11);
                    q.push({r,c});
                }
            }
        }
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)isWater[i][j]^=(1<<11);
        return isWater;
    }
};