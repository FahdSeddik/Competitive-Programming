class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int freq[2002],ffreq[1001];
        memset(freq,0,sizeof(freq)),memset(ffreq,0,sizeof(ffreq));
        for(int v : arr)freq[v+1000]++;
        for(int i=0;i<2002;i++)ffreq[freq[i]]++;
        for(int i=1;i<1001;i++)if(ffreq[i]>1)return false;
        return true;
    }
};


static const int fastio = [](){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    return 0;
}();