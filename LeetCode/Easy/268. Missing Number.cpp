class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bool zeroflag=false;
        long long n = nums.size(),sum=n*(n+1)/2;
        for(const auto& v : nums)zeroflag|=v==0,sum-=v;
        return zeroflag ? sum:0;
    }
};