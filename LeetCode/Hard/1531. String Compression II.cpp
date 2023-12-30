class Solution {
    int freq[101][101],n;
    string st;
public:
    int solve(int i, int K){
        if(n-i<=K) return 0;
        if(freq[i][K]!=-1) return freq[i][K];
        int ans = K?solve(i+1,K-1):101, c = 1;
        int k = K;
        for(int j=i+1;j<=n;j++){
            ans = min(ans,((c>99)?4:(c>9)?3:(c>1)?2:1)+solve(j,k));
            if(j<n and st[i]==st[j]) c++;
            else if(--k<0) break;
        }
        return freq[i][K] = ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(freq,-1,sizeof(freq)),st=s,n=s.length();
        return solve(0,k);
    }
};
/*
4 cases:
1 char: k--, length--
2-9chars: k-=2-9, length-=2
10-99chars: k-=10-99, length-=3
100 chars: k-=100, length-=4
*/

static const int fast_io = [](){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    return 0;
}();