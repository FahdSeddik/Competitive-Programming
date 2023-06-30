class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)return n;
        vector<unordered_map<int,int>> seq(n);
        int ans=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                seq[i][nums[i]-nums[j]]=seq[j].count(nums[i]-nums[j]) ? 1+seq[j][nums[i]-nums[j]] : 2;
                ans=max(ans,seq[i][nums[i]-nums[j]]);
            }
        }
        return ans;
    }
};