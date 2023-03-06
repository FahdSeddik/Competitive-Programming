class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1),ss2(s2);
        unordered_map<string,int> mp;
        string temp;
        while(ss1>>temp)mp[temp]++;
        while(ss2>>temp)mp[temp]++;
        vector<string> ans;
        for(const auto& x : mp)if(x.second==1)ans.push_back(x.first);
        return ans;
    }
};