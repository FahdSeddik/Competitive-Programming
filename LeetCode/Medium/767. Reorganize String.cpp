class Solution {
public:
    string reorganizeString(string s) {
        int freq[26]={0};
        for(auto c : s)freq[c-'a']++;
        vector<pair<int,char>> lets(26);
        for(int i=0;i<26;i++)lets[i]={freq[i],char('a'+i)};
        sort(lets.rbegin(),lets.rend());
        string ans="";
        char c = 'A';
        for(int i=0;i<s.size();i++){
            int idx=-1;
            for(int j=0;idx==-1 && j<26;j++)if(lets[j].first && lets[j].second!=c)idx=j;
            if(idx==-1)return "";
            c=lets[idx].second;
            ans+=c;
            lets[idx].first--;
            sort(lets.rbegin(),lets.rend());
        }
        return ans;
    }
};