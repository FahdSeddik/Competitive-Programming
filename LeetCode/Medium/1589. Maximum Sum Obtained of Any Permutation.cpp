class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        priority_queue<int> pq;
        int n=nums.size(),MOD=1e9+7;
        vector<int> cnt(n+1);
        long long ans=0;
        for(const auto& v : requests)cnt[v[0]]++,cnt[v[1]+1]--;
        partial_sum(cnt.begin(),cnt.end(),cnt.begin());
        for(int i=0;i<n;i++)pq.push(cnt[i]);
        sort(nums.rbegin(),nums.rend());
        int i=0;
        while(!pq.empty()){
            ans=(ans+1LL*pq.top()*nums[i++]%MOD)%MOD;
            pq.pop();
        }
        return ans;
    }
};