class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<int> pq(worker.begin(), worker.end());
        int n=profit.size();
        vector<pair<int,int>> profdif(n);
        for(int i=0;i<n;i++)profdif[i]={profit[i],difficulty[i]};
        sort(profdif.begin(),profdif.end(),[&](auto& a, auto& b){
            return a.first==b.first ? a.second<b.second:a.first<b.first;
        });
        int ans=0;
        for(int i=n-1;i>=0 && !pq.empty();i--){
            while(!pq.empty() && pq.top()>=profdif[i].second)ans+=profdif[i].first,pq.pop();
        }
        return ans;
    }
};