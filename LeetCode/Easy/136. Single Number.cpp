class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(const auto& v : nums)x^=v;
        return x;
    }
};