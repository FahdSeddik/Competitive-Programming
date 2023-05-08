class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans=1;
        for(auto v : nums){
            if(v==0)return 0;
            if(v<0)ans*=-1;
        }
        return ans;
    }
};