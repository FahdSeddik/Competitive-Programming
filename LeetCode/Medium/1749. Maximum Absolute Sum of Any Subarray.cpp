class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=0,best=0,bestmn=0;
        for(int v : nums){
            best=max(v,best+v);
            bestmn=min(v,bestmn+v);
            ans=max(max(best,abs(bestmn)),ans);
        }
        return ans;
    }
};