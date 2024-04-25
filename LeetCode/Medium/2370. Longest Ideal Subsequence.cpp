class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        int maxLen[26]={0};
        for(int i=0;i<n;i++){
            int cur=s[i]-'a';
            int lower=max(0, cur-k);
            int upper=min(25,cur+k);
            for(int j=lower;j<=upper;j++)maxLen[cur]=max(maxLen[cur],maxLen[j]);
            maxLen[cur]++;
        }
        return *max_element(maxLen,maxLen+26);
    }
};