class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mx=INT_MIN;
        for(auto v : nums){
            while(v%2==0)v>>=1;
            mx=max(mx,v);
        }
        vector<int> vals;
        for(auto& v : nums){
            if(v%2){
                vals.push_back(v);
            }else{
                v>>=1;
                while(v>mx)v>>=1;
                vals.push_back(v);
            }
        }
        sort(vals.begin(),vals.end());
        int n=nums.size(),ans = vals[n-1]-vals[0];
        for(int i=0;i<n-1;i++){
            ans = min(ans, max(vals[n - 1], 2 * vals[i]) - min(vals[i + 1], 2 * vals[0]));
        }
        return ans;
    }
};