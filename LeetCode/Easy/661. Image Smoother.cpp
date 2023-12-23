class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                for(int k=-1;k<=1;k++){
                    for(int l=-1;l<=1;l++){
                        if(i+k<0 || i+k>=n || j+l<0 || j+l>=m)continue;
                        ans[i][j]+=img[i+k][j+l],cnt++;
                    }
                }
                ans[i][j]/=cnt;
            }
        }
        return ans;
    }
};