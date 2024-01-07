class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int freq[101];memset(freq,0,sizeof(freq));
        for(auto v : nums)freq[v]++;
        for(int i=0,cnt=0;i<101;i++)if(freq[i]){
            int t=freq[i];
            freq[i]=cnt,cnt+=t;
        }
        for(auto&v : nums)v=freq[v];
        return nums;
    }
};


static const int fastio=[](){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);return 0;}();