class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n=matrix[0].size();
        int l=0,r=m*n-1;
        while(l<=r){
            int mid = (l+r)/2;
            int i=mid/n;
            int j= i==0 ? mid:mid%(i*n);
            if(matrix[i][j]==target)return true;
            if(matrix[i][j]>target)r=mid-1;
            else l=mid+1;
        }   
        return false;
    }
};