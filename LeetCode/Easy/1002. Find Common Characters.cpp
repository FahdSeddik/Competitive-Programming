class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> tot(26,-1);
        for(auto& s : words){
            int freq[26];
            memset(freq,0,sizeof(freq));
            for(char c : s)freq[c-'a']++;
            for(int i=0;i<26;i++)tot[i]=min(tot[i]==-1?INT_MAX:tot[i],freq[i]);
        }
        vector<string> ans;
        for(int i=0;i<26;i++)for(int j=0;j<tot[i];j++)ans.push_back(string(1,'a'+i));
        return ans;
    }
};