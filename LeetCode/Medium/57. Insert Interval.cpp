class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(!intervals.size())return {newInterval};
        vector<vector<int>> ans;
        int mn=INT_MAX,mx=INT_MIN;
        bool first=true;
        for(const auto& v : intervals){
            if(v[0]>newInterval[1]){
                if(mn==INT_MAX && first){
                    ans.push_back(newInterval);
                    first=false;
                }
                else if(first){
                    ans.push_back({mn,mx});
                    first=false;
                }
                ans.push_back(v);
            }
            else if(v[1]<newInterval[0]){
                ans.push_back(v);
            }
            else mn=min(mn,min(v[0],newInterval[0])),mx=max(mx,max(v[1],newInterval[1]));
        }
        if(first){
            if(mn!=INT_MAX)ans.push_back({mn,mx});
            else ans.push_back(newInterval);
        }
        return ans;
    }
};