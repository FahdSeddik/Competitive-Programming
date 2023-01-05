class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())return 0;
        sort(points.begin(),points.end(),[](const vector<int> &a,const vector<int> &b){return a[1]<b[1];});
        int ans=1;
        int lower=points[0][1];
        for(const auto&p : points){
            if(p[0]>lower)ans++,lower=p[1];
        }
        return ans;
    }
};

// [1,6] [2,8] [7,12] [10,16]