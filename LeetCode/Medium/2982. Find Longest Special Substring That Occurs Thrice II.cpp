class Solution {
public:
    int maximumLength(string s) {
        int n = s.length(),freq[26][3]{},ans=0,prev=0;
        for(int i=1,d;i<=n;i++)if(s[i]!=s[i-1]){
            int len=i-prev;d=s[i-1]-'a',prev=i;
            if(freq[d][0]<len)freq[d][2]=freq[d][1],freq[d][1]=freq[d][0],freq[d][0]=len;
            else if(freq[d][1]<len)freq[d][2]=freq[d][1],freq[d][1]=len;
            else if(freq[d][2]<len)freq[d][2]=len;
        }
        for(int i=0;i<26;i++)ans=max(ans,max(freq[i][2],max(freq[i][0]-2,min(freq[i][0]-1,freq[i][1]))));
        return ans==0?-1:ans;
    }
};

static const int fastio=[](){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    return 0;
}();