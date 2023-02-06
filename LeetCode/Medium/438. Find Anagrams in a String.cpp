class Solution {
public:
    vector<int> findAnagrams(string& s, string& p) {
        int n=s.size(),m=p.size();
        int freq[26]={0};
        vector<int> ans;
        for(const auto& c : p)freq[c-'a']++;
        for(int i=0,j=0,cnt=m;i<n;i++){
            freq[s[i]-'a']--;
            if(freq[s[i]-'a']>=0)cnt--;
            if(i-j==m-1){
                if(cnt==0)ans.push_back(j);
                freq[s[j]-'a']++;
                if(freq[s[j]-'a']>0)cnt++;
                j++;
            }
        }
        return ans;
    }
};