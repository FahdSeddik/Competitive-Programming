class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix,int m=0,int n=0) {
        m = matrix.size(),n=matrix[0].size();
        bool z = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)if(matrix[i][j]==0){
                matrix[0][j]=0;
                i>0 ? matrix[i][0]=0:z=true;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++)if(matrix[0][j]==0 || matrix[i][0]==0){
                matrix[i][j]=0;
            }
        }
        if(matrix[0][0]==0)
            for(int i=0;i<m;i++)matrix[i][0]=0;
        if(z)matrix[0]=vector<int>(n);
    }
};