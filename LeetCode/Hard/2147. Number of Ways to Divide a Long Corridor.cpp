class Solution {
public:
    int numberOfWays(string corridor) {
        if(corridor.size()<2)return 0;
        int ans=1;
        int cnt=0,zeyada=0;
        for(auto c : corridor) {
            if(c=='S' && cnt!=2)cnt++;
            else if(c=='S') cnt=1,ans = (1LL*ans*zeyada)%int(1e9+7),zeyada=0;
            if(cnt==2){
                zeyada++;
            }
        }
        if(cnt==0 || cnt==1)return 0;
        return ans;
    }
};