class Solution {
    int m,n;
public:
    int getSubSum(vector<vector<int>>& matrix,int x1, int y1,int x2,int y2) {
        if(x1==0 && y1==0)return matrix[x2][y2];
        if(x1==0)return matrix[x2][y2]-matrix[x2][y1-1];
        if(y1==0)return matrix[x2][y2]-matrix[x1-1][y2];
        return matrix[x2][y2]-matrix[x2][y1-1]-matrix[x1-1][y2]+matrix[x1-1][y1-1];
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        m=matrix.size(),n=matrix[0].size();
        for(int i=1;i<m;i++)matrix[i][0]+=matrix[i-1][0];
        for(int i=1;i<n;i++)matrix[0][i]+=matrix[0][i-1];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                matrix[i][j]+=matrix[i-1][j]+matrix[i][j-1]-matrix[i-1][j-1];
            }
        }
        int ans=0;
        for(int x1=0;x1<m;x1++){
            for(int y1=0;y1<n;y1++){
                for(int x2=x1;x2<m;x2++){
                    for(int y2=y1;y2<n;y2++){
                        if(getSubSum(matrix,x1,y1,x2,y2)==target)ans++;
                    }
                }
            }
        }
        return ans;
    }
};