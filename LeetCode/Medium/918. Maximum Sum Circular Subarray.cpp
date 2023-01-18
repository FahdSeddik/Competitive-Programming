class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int cs1=0,cs2=0,mx=INT_MIN,mn=INT_MAX,tot=0;
        for(const auto& v : nums){
            tot+=v,cs1+=v,cs2+=v;
            mx = max(mx,cs1);
            cs1=max(cs1,0);
            mn = min(mn,cs2);
            cs2=min(cs2,0);
        }
        return tot==mn ? mx : max(mx,tot-mn);
    }
};