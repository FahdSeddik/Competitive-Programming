class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // capital needed , profit
        int n = profits.size();
        vector<pair<int,int>> pc(n);
        for(int i=0;i<n;i++)pc[i]={capital[i],profits[i]};
        sort(pc.begin(),pc.end());
        //0,1,2
        //1,2,3
        priority_queue<int> pq;
        int ans=w,j=0;
        while(k--){
            while(j<n && pc[j].first <=ans)pq.push(pc[j++].second);
            if(pq.empty())break;
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};