class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        int ans=0,r=m-1,c=0;
        while(r>=0 && c<n){
            if(grid[r][c]<0){
                ans+=n-c,r--;
            }else c++;
        }
        return ans;
    }
};