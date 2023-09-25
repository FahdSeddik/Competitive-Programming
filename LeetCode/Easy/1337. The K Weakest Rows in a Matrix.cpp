class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,vector<int>>> temp(mat.size());
        for(int i=0;i<mat.size();i++){
            temp[i].first=i;
            temp[i].second=mat[i];
        }
        sort(temp.begin(),temp.end(),[&](auto& a,auto&b){
            int suma = accumulate(a.second.begin(),a.second.end(),0);
            int sumb = accumulate(b.second.begin(),b.second.end(),0);
            if(suma==sumb)return a.first<b.first;
            return suma<sumb;
        });
        vector<int> ans(k);
        for(int i=0;i<k;i++)ans[i]=temp[i].first;
        return ans;
    }
};