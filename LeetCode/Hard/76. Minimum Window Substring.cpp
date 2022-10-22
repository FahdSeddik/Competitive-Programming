class Solution {
public:
    string minWindow(string s, string t) {
        if(t=="")return "";
        unordered_map<int,int> cntT,window;
        for(auto c : t)cntT[c-'A']++;
        int have = 0,need = cntT.size();
        int start=-1,mnlen=INT_MAX;
        int l=0;
        for(int i=0;i<s.size();i++){
            char r = s[i];
            window[r-'A']++;
            if(cntT.count(r-'A') && window[r-'A']==cntT[r-'A']){
                have++;
            }
            while(have==need){
                if(i-l+1 < mnlen)mnlen = i-l+1,start=l;
                window[s[l]-'A']--;
                if (cntT.count(s[l]-'A') && window[s[l]-'A']<cntT[s[l]-'A']){
                    have--;
                }
                l++;
            }
        }
        return mnlen!=INT_MAX ? s.substr(start,mnlen):"";
    }
};