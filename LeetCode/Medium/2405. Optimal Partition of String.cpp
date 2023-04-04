class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> mp;
        int ans=0;
        for(auto c : s){
            if(mp[c])mp.clear(),mp[c]++,ans++;
            else mp[c]++;
        }
        return ans+int(mp.size()!=0);
    }
};