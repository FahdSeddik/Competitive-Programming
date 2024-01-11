class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> val;
        int n=grid.size();
        for(auto& v : grid){
            int cnt=0;
            for(int i=n-1;i>=0 && !v[i];i--,cnt++);
            val.push_back(cnt);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(val[i]<n-1-i){
                int j=i;
                for(;j<n && val[j]<n-1-i;j++);
                if(j==n)return -1;
                for(;i<j;swap(val[j],val[j-1]),ans++,j--);
            }
        }
        return ans;
    }
};