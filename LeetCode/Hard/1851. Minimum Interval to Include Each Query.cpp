class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        map<int,set<pair<int,int>>> line;
        for(const auto& v : intervals){
            int size = v[1]-v[0]+1;
            line[v[0]].insert({-1,size}),line[v[1]+1].insert({1,size});
        }
        for(int i=0;i<queries.size();i++){
            line[queries[i]].insert({2,i});
        }
        multiset<int> mp;
        vector<int> ans(queries.size(),-1);
        for(auto& [idx,irvs] : line){
            for(auto& irv : irvs){
                if(irv.first==-1)mp.insert(irv.second);
                else if(irv.first==1)mp.erase(mp.find(irv.second));
                else if(!mp.empty())ans[irv.second]=*mp.begin();
            }
        }
        return ans;
    }
};


static const int ahlan = [](){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    return 0;
}();