class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int x=points[0][0],y=points[0][1];
        for(int i=1;i<points.size();i++){
            ans+=max(abs(points[i][0]-x),abs(points[i][1]-y));
            x=points[i][0],y=points[i][1];
        }
        return ans;
    }
};