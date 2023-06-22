class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int,int>> nc;
        long long sum=0,tot=0;
        for(int i=0;i<n;i++)nc.push_back({nums[i],cost[i]}),sum+=cost[i];
        sort(nc.begin(),nc.end());
        int median=0;
        for(int i=0;i<n && tot<(sum+1)/2;i++){
            tot+=nc[i].second,median=nc[i].first;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(1ll*nums[i]-median)*(1ll*cost[i]);
        }
        return ans;
    }
};