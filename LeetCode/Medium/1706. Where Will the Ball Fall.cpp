class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid[0].size(),m=grid.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int r=0,c=i;
            while(r<m && c<n){
                int drc=grid[r][c];
                if((c+drc<0 || c+drc>=n) && r<n){
                    ans[i]=-1;
                    break;
                }
                if(c+drc>0 && c+drc<n){
                    if(grid[r][c+drc]!=drc){ans[i]=-1;break;}
                }
                r++,c+=drc;
            }
            if(r>=m)ans[i]=c;
        }
        return ans;
    }
};