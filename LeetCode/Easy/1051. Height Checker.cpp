class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int he[101]={0},n=heights.size();
        for(const auto& v : heights) he[v]++;
        int idx=0,ans=0;
        for(int i=0;i<101;i++){
            if(he[i]){
                while(idx<n && he[i]){
                    if(heights[idx++]!=i)ans++;
                    --he[i];
                }
            }
        }
        return ans;
    }
};