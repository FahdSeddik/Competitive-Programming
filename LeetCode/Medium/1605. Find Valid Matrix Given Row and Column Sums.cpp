class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(),m=colSum.size();
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int mn = min(rowSum[j],colSum[i]);
                rowSum[j]-=mn;
                colSum[i]-=mn;
                ans[j][i]=mn;
            }
        }
        return ans;
    }
};


/*

[0,0,0]
[0,0,0]


5   0   0
3   4   0
0   2   8

*/