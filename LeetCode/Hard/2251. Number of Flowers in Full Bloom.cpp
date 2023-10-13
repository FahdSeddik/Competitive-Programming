class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> s,e,ans;
        for(auto& v : flowers)s.push_back(v[0]),e.push_back(v[1]);
        sort(s.begin(),s.end()),sort(e.begin(),e.end());
        for(auto p : people){
            ans.push_back(int(upper_bound(s.begin(),s.end(),p)-s.begin())-int(lower_bound(e.begin(),e.end(),p)-e.begin()));
        }
        return ans;
    }
};