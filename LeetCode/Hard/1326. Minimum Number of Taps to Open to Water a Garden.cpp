class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> mxRng(n+1,0);
        for(int i=0;i<=n;i++){
            mxRng[max(0,i-ranges[i])]=max(mxRng[max(0,i-ranges[i])],min(n,i+ranges[i]));
        }
        int end=0,farthest=0,ans=0,i=0;
        while(end<n){
            while(i<=end){
                farthest=max(farthest,mxRng[i++]);
            }
            if(farthest<=end)return -1;
            end=farthest;
            ans++;
        }
        return ans;
    }
};