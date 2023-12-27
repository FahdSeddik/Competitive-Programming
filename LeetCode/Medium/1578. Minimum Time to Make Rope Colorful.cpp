class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cnt=0,mx=0,sum=0;
        char cur='_';
        int ans=0;
        for(int i=0;i<colors.size();i++){
            if(cur!=colors[i]){
                if(cnt>=2) {
                    ans+=sum-mx;
                }
                cnt=1,mx=sum=neededTime[i],cur=colors[i];
            } else {
                cnt++,mx=max(neededTime[i],mx),sum+=neededTime[i];
            }
        }
        if(cnt>=2)ans+=sum-mx;
        return ans;
    }
};