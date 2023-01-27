class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int t[n+1];
        memset(t,0,sizeof(t));
        for(const auto& h : trust){
            t[h[1]]++;
            t[h[0]]--;
        }
        for(int i=1;i<=n;i++)if(t[i]==n-1)return i;
        return -1;
    }
};