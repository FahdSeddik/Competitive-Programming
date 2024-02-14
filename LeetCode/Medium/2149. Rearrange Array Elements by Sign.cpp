class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), i=0,j=1;
        vector<int> ans(n);
        for(int v : nums){
            if(v>0)ans[i]=v,i+=2;
            else ans[j]=v,j+=2;
        }
        return ans;
    }
};

static const int fastio = [](){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    return 0;
}();