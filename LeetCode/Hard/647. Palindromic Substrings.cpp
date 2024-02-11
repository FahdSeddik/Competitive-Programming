class Solution {
    int ans = 0;
public:
    int countSubstrings(string s) {
        for(int i=0;i<s.size();i++){
            expandAround(s,i);
        }
        return ans;
    }
    void expandAround(string&s,int idx){
        int i=idx,j=idx;
        while(i<s.size() && j>=0 && s[i]==s[j])i++,j--,ans++;
        j=idx-1,i=idx;
        while(i<s.size() && j>=0 && s[i]==s[j])i++,j--,ans++;
    }
};