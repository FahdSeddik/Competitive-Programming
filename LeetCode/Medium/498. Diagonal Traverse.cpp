class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> mp(m+n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ans(m*n);
        for(int i=0,idx=0;i<m+n;i++){
            if(!mp[i].size())continue;
            if(i%2)for(const auto& e : mp[i])ans[idx++]=e;
            else for(int j=mp[i].size()-1;j>=0;j--)ans[idx++]=mp[i][j];
        }
        return ans;
    }
};


/*

0    0 1 2 3
1    0 1 2 3
2    0 1 2 3
3    0 1 2 3
4    0 1 2 3

0 1 2 3 4
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8




*/