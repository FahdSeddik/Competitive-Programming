class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& ivs) {
        int n = ivs.size();
        for(int i=0;i<n;i++)ivs[i].push_back(i);
        sort(ivs.begin(),ivs.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int l =0,r=n-1,target=ivs[i][1];
            while(l<r){
                int mid = (l+r)/2;
                if(ivs[mid][0]<target)l=mid+1;
                else r=mid;
            }
            ans[ivs[i][2]]= (ivs[r][0]>=target) ? ivs[r][2]:-1;
        }
        return ans;
    }
};