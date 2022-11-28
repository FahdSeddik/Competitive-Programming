class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<long long,int>> mps(n);
        long long ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long long diff = (long long)nums[i]-(long long)nums[j];
                int sum=0;
                if(mps[j].count(diff)){
                    sum = mps[j][diff];
                }
                mps[i][diff] += sum + 1;
                ans+=sum;
            }
        }
        return ans;
    }
};