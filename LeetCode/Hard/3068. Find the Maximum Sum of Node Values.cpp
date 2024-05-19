class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long cntPos = 0, minPos = INT_MAX, maxNeg = INT_MIN, sum = 0;
        for(int v : nums){
            long long  xored = v^k, change = xored-v;
            sum+=v;
            if(change>0)cntPos++,minPos=min(minPos,change),sum+=change;
            else maxNeg=max(maxNeg,change);
        }
        return cntPos%2==0 ? sum:max(sum-minPos,sum+maxNeg);
    }
};