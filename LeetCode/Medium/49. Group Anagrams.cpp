class Solution {
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto v : mp){
            res.push_back(v.second);
        }
        return res;
    }
};