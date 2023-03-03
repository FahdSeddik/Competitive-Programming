class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(1,1);
        for(int i=1;i<rowIndex+1;i++){
            vector<int> row(i+1,1);
            for(int j=1;j<=i/2;j++){
                row[j]=row[i-j]=dp[j-1]+dp[j];
            }
            dp=row;
        }
        return dp;
    }
};