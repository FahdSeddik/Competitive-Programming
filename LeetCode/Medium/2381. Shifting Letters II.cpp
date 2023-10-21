class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> cnt(n+1);
        for(const auto& v : shifts){
            int chng=v[2] ? 1:-1;
            cnt[v[0]]+=chng,cnt[v[1]+1]-=chng;
        }
        int cur=0;
        for(int i=0;i<n;i++){
            cur+=cnt[i];
            s[i]=((s[i] - 'a' + cur) % 26 +26)%26 + 'a';
        }
        return s;
    }
};