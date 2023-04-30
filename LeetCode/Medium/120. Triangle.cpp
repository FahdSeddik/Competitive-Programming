class Solution {
   public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        if(n==1)return t[0][0];
        for(int i=n-2;i>0;i--){
           for(int j=0;j<i;j++){
               t[i][j]+=min(t[i+1][j+1],t[i+1][j]);
           }
           t[i][i]+=min(t[i+1][i],t[i+1][i+1]);
        }
        return t[0][0]+min(t[1][0],t[1][1]);
    }
};