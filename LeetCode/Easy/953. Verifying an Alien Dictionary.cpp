class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order,int i=0) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        unordered_map<char,char> mp;
        for(const auto& c : order)mp[c]=char(i++ + 'a');
        vector<string> check(words.size());
        for(i=0;i<words.size();i++){
            string conv;
            for(const auto& c : words[i])conv+=mp[c];
            words[i]=conv;
            check[i]=conv;
        }
        sort(check.begin(),check.end());
        for(i=0;i<words.size();i++)if(check[i]!=words[i])return false;
        return true;
    }
};