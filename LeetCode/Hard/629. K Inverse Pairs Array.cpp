class Solution {
private:
    const int mod=int(1e9+7);
public:
    int kInversePairs(int n, int k) {
        vector<int> prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=1;
        for(int N=1;N<=n;++N) {
            curr[0]=prev[0];
            for(int K=1;K<=k;++K) {
                curr[K] = (prev[K] + curr[K - 1]) % mod;
                curr[K] = (curr[K] + mod - (K >= N ? prev[K-N] : 0)) % mod;
            }
            prev = curr;
        }
        return curr[k];
    }
};