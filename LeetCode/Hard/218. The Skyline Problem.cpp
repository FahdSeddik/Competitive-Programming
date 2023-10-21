class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<int> mp{0};
        vector<pair<int,int>> pts;
        for(const auto& v : buildings){
            pts.push_back({v[0],-v[2]}),pts.push_back({v[1],v[2]});
        }
        sort(pts.begin(),pts.end());
        int cur=0;
        for(auto& pt : pts){
            int h=pt.second;
            if(h<0)mp.insert(-h);
            else mp.erase(mp.find(h));
            if(cur!=*mp.rbegin()){
                cur=*mp.rbegin();
                ans.push_back({pt.first,cur});
            }
        }
        return ans;
    }
};