class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> pyramid(query_row+2,vector<double>(query_row+2));
        pyramid[0][0]=poured;
        for(int r=0;r<=query_row;r++){
            for(int c=0;c<=r;c++){
                double q = (pyramid[r][c]-1.0)/2.0;
                if(q>0)pyramid[r+1][c]+=q,pyramid[r+1][c+1]+=q;
            }
        }
        cout<<pyramid[query_row][query_glass];
        return min(1.0,pyramid[query_row][query_glass]);
    }
};