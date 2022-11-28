class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        if(n%2==0){
            int j=1;
            for(int i=0;i<n-1;i+=2,j++){
                ans[i]=j,ans[i+1]=-j;
            }
        }else{
            ans[0]=0;
            int j=1;
            for(int i=1;i<n-1;i+=2,j++){
                ans[i]=j,ans[i+1]=-j;
            }
        }
        return ans;
    }
};