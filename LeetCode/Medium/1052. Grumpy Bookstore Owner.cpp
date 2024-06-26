class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int tot=0,ans,sum;
        for(int i=0;i<n;i++)if(!grumpy[i])tot+=customers[i],customers[i]=0;
        sum=accumulate(customers.begin(),customers.begin()+minutes,0),ans=sum;
        for(int i=minutes;i<n;i++)sum+=customers[i]-customers[i-minutes],ans=max(ans,sum);
        return ans+tot;
    }
};