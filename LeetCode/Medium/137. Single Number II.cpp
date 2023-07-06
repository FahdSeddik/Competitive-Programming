class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int o = 0, r = 0;
        for(auto n: nums)
            o = (~r) & (o ^ n), r = (~o) & (r ^ n);
        return o;
    }
};