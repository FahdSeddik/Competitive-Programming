class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int dr=1,dc=1;
        for(int i=0;i<matrix.size();i++){
            int r=i,c=0;
            int n=matrix[r][c];
            while(r<matrix.size() && c<matrix[0].size()){
                if(matrix[r][c]!=n)return false;
                r+=dr,c+=dc;
            }
        }
        for(int i=1;i<matrix[0].size();i++){
            int c=i,r=0;
            int n=matrix[r][c];
            while(r<matrix.size() && c<matrix[0].size()){
                if(matrix[r][c]!=n)return false;
                r+=dr,c+=dc;
            }
        }
        return true;
    }
};