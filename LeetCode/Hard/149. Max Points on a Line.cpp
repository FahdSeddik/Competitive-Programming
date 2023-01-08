class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2)return n;
        int ans=0;
        for(int i=0;i<points.size()-1;i++){
            double x1=points[i][0],y1=points[i][1];
            unordered_map<double,int> lines;
            for(int j=i+1;j<points.size();j++){
                double x2=points[j][0],y2=points[j][1],slope;
                if(x2-x1==0)slope=INT_MAX;
                else slope=(y2-y1)/(x2-x1);
                lines[slope]++;
                ans = max(ans,lines[slope]);
            }
        }
        return ans+1; 
    }
};