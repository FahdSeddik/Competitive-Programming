class Solution {
public:
    vector<int> constructArray(int n, int k,int idx=0) {
        vector<int> ans(n);
        for(int i=1,j=n;i<=j;){
            if(k)ans[idx++]=k-- %2 ? i++:j--;
            else ans[idx++]=i++;
        }
        return ans;
    }
};