class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int diff=0,last=nums[0];
        int ans=0;
        for(auto v : nums){
            if(last!=v)last=v,diff++;
            ans+=diff;
        }
        return ans;
    }
};

static const int io = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return 0;
}();