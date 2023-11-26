class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(),n=matrix[0].size();
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j])matrix[i][j]+=matrix[i-1][j];
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            sort(matrix[i].rbegin(),matrix[i].rend());
            for(int j=0;j<n;j++)ans=max(ans,matrix[i][j]*(j+1));
        }
        return ans;
    }
};



static const int io = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return 0;
}();