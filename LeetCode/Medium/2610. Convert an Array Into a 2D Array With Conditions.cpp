class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int freq[201],idx[201];
        memset(freq,0,sizeof(freq)),memset(idx,0,sizeof(idx));
        for(auto v : nums)freq[v]++;
        vector<vector<int>> ans;
        for(int i=0;i<201;i++){
            for(int j=0;j<freq[i];j++){
                if(ans.size() < freq[i]) {
                    ans.push_back({i});
                } else {
                    ans[idx[i]].push_back(i);
                    idx[i]++;
                }
            }
        }
        return ans;
    }
};