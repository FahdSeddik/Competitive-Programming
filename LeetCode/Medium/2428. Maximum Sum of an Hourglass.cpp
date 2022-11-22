class Solution {
public:
    int maxSum(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        int res = INT_MIN;
        for (int i = 2; i < m; i++) {
            for (int j = 2; j < n; j++) {
                int sum = 0;
                sum += a[i-2][j-2];
                sum += a[i-2][j-1];
                sum += a[i-2][j];
                sum += a[i-1][j-1];
                sum += a[i][j-2];
                sum += a[i][j-1];
                sum += a[i][j];
                res = max(res, sum);
            }
        }
        return res;
    }
};