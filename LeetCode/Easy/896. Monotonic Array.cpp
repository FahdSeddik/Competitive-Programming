static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc=true,dec=true;
        for(int i=0;i<nums.size()-1;i++){
            inc&=nums[i]<=nums[i+1];
            dec&=nums[i]>=nums[i+1];
        }
        return inc|dec;
    }
};