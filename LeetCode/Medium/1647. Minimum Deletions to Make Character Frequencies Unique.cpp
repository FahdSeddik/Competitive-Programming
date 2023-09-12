class Solution {
public:
    int minDeletions(string s) {
        vector<int> freqs;
        int mp[26] = {0};
        unordered_set<int> totfreqs;
        for(auto c:s)mp[c-'a']++;
        for(int i=0;i<26;i++)if(mp[i])freqs.push_back(mp[i]);
        sort(freqs.begin(),freqs.end());
        int ans=0;
        for(int i=freqs.size()-1;i>=0;i--){
            while(freqs[i] && totfreqs.count(freqs[i]))freqs[i]--,ans++;
            totfreqs.insert(freqs[i]);
        }
        return ans;
    }
};