class Solution {
    int lr,ur,lc,uc;
    vector<int> dx{1,0,-1,0},dy{0,1,0,-1};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans(matrix.size()*matrix[0].size());
        lr=lc=-1;ur=matrix.size(),uc=matrix[0].size();
        int index=0,diri=0;
        int i=lr+1,j=lc+1;
        while(lr<ur && lc<uc){
            while(i<ur && i>lr && j<uc && j>lc){
                ans[index++]=matrix[i][j];
                i+=dy[diri],j+=dx[diri];
            }
            i-=dy[diri],j-=dx[diri];
            if(diri==0)lr++;
            else if(diri==1)uc--;
            else if(diri==2)ur--;
            else if(diri==3)lc++;
            diri = (diri+1)%4;
            i+=dy[diri],j+=dx[diri];
        }
        return ans;
    }
};