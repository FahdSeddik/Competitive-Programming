class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<pair<int,pair<int,int>>> temp;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                temp.push_back({i+j,{i,nums[i][j]}});
            }
        }
        sort(temp.begin(),temp.end(),[&](auto& a, auto& b){
            if(a.first==b.first){
                return a.second.first>b.second.first;
            }else return a.first<b.first;
        });
        vector<int> ans;
        for(auto& x : temp)ans.push_back(x.second.second);
        return ans;
    }
};