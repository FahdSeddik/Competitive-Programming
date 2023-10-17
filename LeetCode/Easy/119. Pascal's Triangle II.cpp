class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1,1);
        long long cur=rowIndex;
        for(int i=1;i<=rowIndex/2;i++){
            ans[i]=ans[rowIndex-i]=cur,cur=cur*(rowIndex-i)/(i+1);
        }
        return ans;
    }
};