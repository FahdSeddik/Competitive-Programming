class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& irv) {
        sort(irv.begin(),irv.end(), [&](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        });
        int mn = irv[0][0],mx=irv[0][1];
        vector<vector<int>> ans;
        for(int i=1;i<irv.size();i++){
            if(mx>=irv[i][0])mx = max(mx,irv[i][1]);
            else{
                ans.push_back({mn,mx});
                mn=irv[i][0],mx=irv[i][1];
            }
        }
        ans.push_back({mn,mx});
        return ans;
    }
};