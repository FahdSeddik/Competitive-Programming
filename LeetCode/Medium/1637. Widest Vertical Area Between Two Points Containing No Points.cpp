class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[&](auto&a,auto&b){
            return a[0]<b[0];
        });
        int mx=0;
        for(int i=0;i<points.size()-1;i++)mx=max(points[i+1][0]-points[i][0],mx);
        return mx;
    }
};