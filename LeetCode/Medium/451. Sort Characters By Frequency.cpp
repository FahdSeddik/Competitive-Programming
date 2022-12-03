class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> chars;
        for(auto c:s)chars[c]++;
        vector<pair<int,char>> fr;
        for(auto x:chars)if(x.second)fr.push_back({x.second,x.first});
        sort(fr.begin(),fr.end(),greater<pair<int,char>>());
        string ans="";
        for(auto p:fr){
            for(int i=0;i<p.first;i++)ans+=p.second;
        }
        return ans;
    }
};