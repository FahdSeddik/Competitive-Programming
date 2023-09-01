class Solution {
public:
    double calc(double a, double b){
        return (a+1.0)/(b+1.0) - a/b;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<classes.size();i++){
            pq.push({calc(classes[i][0],classes[i][1]),i});
        }
        while(extraStudents){
            auto x = pq.top();
            pq.pop();
            int i = x.second;
            classes[i][0]++,classes[i][1]++;
            pq.push({calc(classes[i][0],classes[i][1]),i});
            extraStudents--;
        }
        double ans=0;
        for(auto& v: classes)ans+=double(v[0])/v[1];
        return ans/classes.size();
    }
};