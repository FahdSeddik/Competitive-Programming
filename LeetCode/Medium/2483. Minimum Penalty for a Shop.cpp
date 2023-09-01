class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> sum1(n+1),sum2(n+1);
        for(int i=0;i<n;i++){
            sum1[i+1]=sum1[i]+int(customers[i]=='N');
            sum2[n-i-1]=sum2[n-i]+int(customers[n-i-1]=='Y');
        }
        int mn=INT_MAX,mni=-1;
        for(int i=0;i<=n;i++){
            int penalty = sum1[i]+sum2[i];
            if(penalty<mn)mn=penalty,mni=i;
        }
        return mni;
    }
};