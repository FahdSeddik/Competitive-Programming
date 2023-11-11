class Solution {
    vector<int> ans;
    unordered_map<int,vector<int>> mp;
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(auto& v : adjacentPairs){
            mp[v[0]].push_back(v[1]);
            mp[v[1]].push_back(v[0]);
        }
        int start = 0;
        for(auto& x : mp)if(x.second.size()==1){
            start=x.first;
            break;
        }
        ans.push_back(start);
        ans.push_back(mp[start][0]);
        int last = start;
        while(ans.size()<mp.size()){
            int next = mp[ans.back()][0]==last ? mp[ans.back()][1]:mp[ans.back()][0];
            last=ans.back();
            ans.push_back(next);
        }
        return ans;
    }
};