class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> merged;
        for(int i=0;i<n;i++)merged.push_back({nums2[i],nums1[i]});
        sort(merged.rbegin(),merged.rend());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long cursum=0;
        for(int i=0;i<k-1;i++){
            pq.push(merged[i].second);
            cursum+=merged[i].second;
        }
        long long ans=0;
        for(int i=k-1;i<n;i++){
            cursum+=merged[i].second;
            pq.push(merged[i].second);
            ans = max(ans,cursum*merged[i].first);
            cursum-=pq.top();pq.pop();
        }
        return ans;
    }
};