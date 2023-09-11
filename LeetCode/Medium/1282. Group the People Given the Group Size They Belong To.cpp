class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto& x : mp){
            vector<int> cur;
            int sz = x.first;
            for(auto i : x.second){
                if(cur.size()==sz)ans.push_back(cur),cur.clear();
                cur.push_back(i);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};